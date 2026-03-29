#include <bits/stdc++.h>
using namespace std;

/*
  Multi-word Myers bit-parallel algorithm (fixed)
  - Hỗ trợ pattern dài bất kỳ (chia thành block 64-bit)
  - Trim '\r' trên input lines (Windows CRLF)
  - Nếu compile với -DDEBUG sẽ so sánh kết quả với DP O(n*m) cho input nhỏ
*/

int myers_multiblock(const string &text_, const string &pattern_) {
    const int W = 64;
    // local copies (we won't modify originals)
    string text = text_;
    string pattern = pattern_;

    int n = (int)text.size();
    int m = (int)pattern.size();
    if (m == 0) return n;
    if (n == 0) return m;

    int words = (m + W - 1) / W;

    // Peq[c][w]
    vector<vector<uint64_t>> Peq(256, vector<uint64_t>(words, 0ULL));
    for (int i = 0; i < m; ++i) {
        unsigned char c = (unsigned char)pattern[i];
        int w = i / W;
        int b = i % W;
        Peq[c][w] |= (1ULL << b);
    }

    // masks for last block
    int last_bits = m % W;
    uint64_t last_block_mask = (last_bits == 0) ? ~0ULL : ((1ULL << last_bits) - 1ULL);
    uint64_t highest_bit_mask = (1ULL << ((m - 1) % W)); // bit of pattern index m-1 inside last block

    // VP, VN per block
    vector<uint64_t> VP(words, ~0ULL), VN(words, 0ULL);
    // ensure bits beyond pattern length are zeroed in last block
    VP[words - 1] &= last_block_mask;
    VN[words - 1] &= last_block_mask;

    int score = m;

    for (int i = 0; i < n; ++i) {
        unsigned char ch = (unsigned char)text[i];

        uint64_t carryHP = 0; // carry into next block for HP shift
        uint64_t carryHN = 0; // carry into next block for HN shift

        uint64_t last_HP = 0, last_HN = 0; // HP/HN of last block (pre-shift), used to update score

        for (int w = 0; w < words; ++w) {
            uint64_t Peqw = Peq[ch][w];
            uint64_t Pv = VP[w];
            uint64_t Nv = VN[w];

            uint64_t X = Peqw | Nv;
            uint64_t tmp = X & Pv;
            uint64_t D0 = (((tmp + Pv) ^ Pv) | X);

            uint64_t HN = Pv & D0;
            uint64_t HP = Nv | ~(Pv | D0);

            if (w == words - 1) {
                last_HP = HP;
                last_HN = HN;
            }

            uint64_t HP_shift = (HP << 1) | carryHP;
            uint64_t HN_shift = (HN << 1) | carryHN;

            // compute carry outs for next block (from current HP/HN)
            carryHP = (HP >> (W - 1)) & 1ULL;
            carryHN = (HN >> (W - 1)) & 1ULL;

            VP[w] = HN_shift | ~(D0 | HP_shift);
            VN[w] = HP_shift & D0;

            // mask last block's high bits beyond pattern length
            if (w == words - 1) {
                VP[w] &= last_block_mask;
                VN[w] &= last_block_mask;
            }
        } // end blocks

        // update score using HP/HN of last block BEFORE shift (as in Myers)
        if (last_HP & highest_bit_mask) ++score;
        else if (last_HN & highest_bit_mask) --score;
    } // end text chars

    return score;
}

#ifdef DEBUG
// simple DP Levenshtein for debug (O(n*m))
int levenshtein_dp(const string &A, const string &B) {
    int n = A.size(), m = B.size();
    vector<int> dp(m+1);
    for (int j=0;j<=m;++j) dp[j]=j;
    for (int i=1;i<=n;++i){
        int prev = dp[0];
        dp[0]=i;
        for (int j=1;j<=m;++j){
            int cur = dp[j];
            if (A[i-1]==B[j-1]) dp[j]=prev;
            else dp[j]=min({prev+1, dp[j-1]+1, dp[j]+1});
            prev = cur;
        }
    }
    return dp[m];
}
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    if (!getline(cin, A)) return 0;
    if (!getline(cin, B)) return 0;
    // strip Windows CR if present
    if (!A.empty() && A.back() == '\r') A.pop_back();
    if (!B.empty() && B.back() == '\r') B.pop_back();

    // For performance, choose pattern = shorter string
    string T = A, P = B;
    if (P.size() > T.size()) swap(T, P);

#ifdef DEBUG
    // debug: compute DP for small sizes and compare
    if (1LL * T.size() * P.size() <= 20000000) { // limit DP to ~20M ops
        int dp_ans = levenshtein_dp(T, P);
        int myers_ans = myers_multiblock(T, P);
        if (dp_ans != myers_ans) {
            cerr << "DEBUG MISMATCH! dp=" << dp_ans << " myers=" << myers_ans << "\n";
        } else {
            cerr << "DEBUG OK: distance=" << myers_ans << "\n";
        }
        cout << myers_ans << "\n";
        return 0;
    }
#endif

    int ans = myers_multiblock(T, P);
    cout << ans << '\n';
    return 0;
}
