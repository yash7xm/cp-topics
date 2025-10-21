#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

// Extended Euclidean algorithm
int64 extgcd(int64 a, int64 b, int64 &x, int64 &y) {
    if (b == 0) { x = (a >= 0 ? 1 : -1); y = 0; return llabs(a); }
    int64 x1, y1;
    int64 g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

bool solve(int64 X, int64 Y, int sign, int64 &A, int64 &B) {
    // Equation: (-Y)*A + X*B = sign * 2
    int64 a = -Y, b = X;
    int64 x0, y0;
    int64 g = extgcd(a, b, x0, y0);
    if ((sign * 2) % g != 0) return false;

    i128 mult = (sign * 2) / g;
    i128 A0 = (i128)x0 * mult;
    i128 B0 = (i128)y0 * mult;

    i128 stepA = b / g;
    i128 stepB = -a / g;

    const i128 L = -1000000000000000000LL;
    const i128 R =  1000000000000000000LL;

    auto range = [&](i128 base, i128 step) -> pair<i128,i128> {
        if (step == 0) {
            if (base < L || base > R) return {1, 0};
            return {LLONG_MIN, LLONG_MAX};
        }
        long double k1 = (long double)(L - base) / (long double)step;
        long double k2 = (long double)(R - base) / (long double)step;
        if (k1 > k2) swap(k1, k2);
        return {(i128)ceil(k1), (i128)floor(k2)};
    };

    auto [l1, r1] = range(A0, stepA);
    auto [l2, r2] = range(B0, stepB);
    i128 Lk = max(l1, l2);
    i128 Rk = min(r1, r2);

    if (Lk > Rk) return false;

    i128 k = Lk;
    A = (long long)(A0 + stepA * k);
    B = (long long)(B0 + stepB * k);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 X, Y;
    cin >> X >> Y;

    int64 A, B;
    if (solve(X, Y, 1, A, B) || solve(X, Y, -1, A, B))
        cout << A << ' ' << B << '\n';
    else
        cout << -1 << '\n';
}

