#include <bits/stdc++.h>
using namespace std;

/*
  Multi-word Myers bit-parallel Levenshtein distance (final fixed)
  - Supports arbitrary pattern length m (split into 64-bit blocks)
  - Strips CRLF '\r'
  - Updates score using HP/HN of last block BEFORE shifting
  - Masks bits beyond pattern length in last block
*/

int myers_multiblock(const string &text_, const string &pattern_) {
    const int W = 64;
    string text = text_;
    string pattern = pattern_;

    int n = (int)text.size();
    int m = (int)pattern.size();
    if (m == 0) return n;
    if (n == 0) return m;

    int words = (m + W - 1) / W;

    // Peq[c][w]: for each byte value c, a vector of bitmasks (one per block)
    vector<vector<uint64_t>> Peq(256, vector<uint64_t>(words, 0ULL));
    for (int i = 0; i < m; ++i) {
        unsigned char c = (unsigned char)pattern[i];
        int w = i / W;
        int b = i % W;
        Peq[c][w] |= (1ULL << b);
    }

    // Masks for last block
    int last_bits = m % W;
    uint64_t last_block_mask = (last_bits == 0) ? ~0ULL : ((1ULL << last_bits) - 1ULL);
    uint64_t highest_bit_mask = (1ULL << ((m - 1) % W)); // bit corresponding to pattern index m-1 in last block

    // VP, VN per block initialization
    vector<uint64_t> VP(words, ~0ULL), VN(words, 0ULL);
    // ensure bits beyond pattern length are zero in last block
    VP[words - 1] &= last_block_mask;
    VN[words - 1] &= last_block_mask;

    int score = m;

    // main loop over text characters
    for (int ti = 0; ti < n; ++ti) {
        unsigned char ch = (unsigned char)text[ti];

        uint64_t carryHP = 0; // carry into next block for HP_shift
        uint64_t carryHN = 0; // carry into next block for HN_shift

        uint64_t last_HP = 0, last_HN = 0; // HP/HN of last block BEFORE shift

        for (int w = 0; w < words; ++w) {
            uint64_t Peqw = Peq[ch][w];
            uint64_t Pv = VP[w];
            uint64_t Nv = VN[w];

            uint64_t X = Peqw | Nv;
            uint64_t tmp = X & Pv;
            uint64_t D0 = (((tmp + Pv) ^ Pv) | X);

            uint64_t HN = Pv & D0;
            uint64_t HP = Nv | ~(Pv | D0);

            // capture HP/HN of last block BEFORE shift to update score later
            if (w == words - 1) {
                last_HP = HP;
                last_HN = HN;
            }

            // shift with carry from previous block
            uint64_t HP_shift = (HP << 1) | carryHP;
            uint64_t HN_shift = (HN << 1) | carryHN;

            // compute carry-out (bit that overflows to next block)
            carryHP = (HP >> (W - 1)) & 1ULL;
            carryHN = (HN >> (W - 1)) & 1ULL;

            // update VP and VN for this block
            VP[w] = HN_shift | ~(D0 | HP_shift);
            VN[w] = HP_shift & D0;

            // mask last block to clear bits beyond pattern length
            if (w == words - 1) {
                VP[w] &= last_block_mask;
                VN[w] &= last_block_mask;
            }
        } // end blocks loop

        // update global score using last_HP/last_HN (before shift)
        if (last_HP & highest_bit_mask) ++score;
        else if (last_HN & highest_bit_mask) --score;
    } // end text chars

    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    if (!getline(cin, A)) return 0;
    if (!getline(cin, B)) return 0;
    // strip CR if present (Windows CRLF)
    if (!A.empty() && A.back() == '\r') A.pop_back();
    if (!B.empty() && B.back() == '\r') B.pop_back();

    // For efficiency, use the shorter string as pattern (fewer blocks)
    string T = A, P = B;
    if (P.size() > T.size()) swap(T, P);

    int ans = myers_multiblock(T, P);
    cout << ans << '\n';
    return 0;
}
