#include <sys/uio.h>
iovec iovI, iovO;
 
const int BUF_SIZ = 65536, MAX = 1073741824;
char r, *bp, *br, buf[BUF_SIZ];
int in;
inline void read() {
    r=(bp==br&&(br=(bp=buf)+readv(0, &iovI, 1))==buf)?33:*bp++;
}
inline void nextInt() {
    while(r<33) read();
    for(in=0; r>47; read()) in = in*10 +r-48;
}
 
const int OUT_SIZ = 65536, DIGIT = 10;
char out[OUT_SIZ], *ap=out, *LIMIT = out+OUT_SIZ-DIGIT-3;
inline void flush() {
    iovO.iov_len = ap-out;
    writev(1, &iovO, 1);
    ap = out;
}
inline void printInt(int &x) {
    static char num[DIGIT], *END = num+DIGIT, *n;
    in = x;
    for(n=END; x>=10; x/=10) *--n = x%10 + 48;
    *--n = x+48;
    while(n<END) *ap++ = *n++;
    x = MAX;
}
 
inline int& min(int &a, int &b) {
    return a<b?a:b;
}
 
const int ARR_SIZ = 200000, BAS = 262144;
int N, M, i, bst[BAS<<1], *arr=bst+BAS;
 
inline void radSort(int a[], const int &N) {
    static const int RAD_SIZ = 32768, MOD = RAD_SIZ-1;
    static int i, p[RAD_SIZ+1], *c=p+1, t[ARR_SIZ];
    for(int &x: p)      x=0; p[0] = -1;
    for(i=0; i<N;       ++i) ++c[a[i]&MOD];
    for(i=0; i<RAD_SIZ; ++i) c[i] += c[i-1];
    for(i=0; i<N;       ++i) t[++p[a[i]&MOD]] = a[i];
    for(int &x: p)      x=0; p[0] = -1;
    for(i=0; i<N;       ++i) ++c[t[i]>>15];
    for(i=0; i<RAD_SIZ; ++i) c[i] += c[i-1];
    for(i=0; i<N;       ++i) a[++p[t[i]>>15]] = t[i];
}
 
int main() {
 
    iovI.iov_base = buf;
    iovI.iov_len = BUF_SIZ;
    iovO.iov_base = out;
 
    nextInt(), N=in;
    nextInt(), M=in;
    for(i=0; i<N; ++i) nextInt(), arr[i]=in;
    radSort(arr, N);
 
    for(i=BAS; --i; bst[i]=bst[i<<1]);
    for(i=1; i<BAS;)
        if(bst[i=i<<1|1]==0) bst[i--] = MAX;
 
    while(M--) {
        nextInt();
        for(i=1; i<BAS;)
            if(bst[i=i<<1|1]>in && bst[--i]>in)
                i = MAX;
        if(i<MAX) {
            for(printInt(bst[i]); bst[i>>=1]==in;)
                bst[i] = min(bst[i<<1], bst[i<<1|1]);
        }else *ap++=45, *ap++=49;
        *ap++ = 10;
        if(ap>LIMIT) flush();
    }
    flush();
 
}