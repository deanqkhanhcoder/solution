#include <bits/stdc++.h>
#include <cmath>
using namespace std;
long double PI = acosl(-1.0L);
const int N = 45;
const double EPS = 1e-15;

// Tính P_n(x) và P_{n-1}(x)
pair<double, double> legendre(int n, double x) {
    double P0 = 1.0;
    double P1 = x;

    if (n == 0) return {P0, 0};
    if (n == 1) return {P1, P0};

    for (int i = 2; i <= n; i++) {
        double Pn = ((2.0*i - 1.0)*x*P1 - (i - 1.0)*P0) / i;
        P0 = P1;
        P1 = Pn;
    }
    return {P1, P0}; // P_n , P_{n-1}
}

int main() {
    cout << fixed << setprecision(15);

    vector<double> roots(N);

    for (int k = 1; k <= N; k++) {
        // Giá trị khởi tạo xấp xỉ
        double x = cos(PI * (4.0*k - 1.0) / (4.0*N + 2.0));

        // Newton-Raphson
        while (true) {
            auto val = legendre(N, x);
            double Pn = val.first;
            double Pn_1 = val.second;

            double dPn = (N * (x * Pn - Pn_1)) / (x*x - 1.0);

            double x_new = x - Pn / dPn;

            if (abs(x_new - x) < EPS)
                break;

            x = x_new;
        }

        roots[k-1] = x;
    }

    sort(roots.begin(), roots.end());

    for (double r : roots)
        cout << r << "\n";

    return 0;
}