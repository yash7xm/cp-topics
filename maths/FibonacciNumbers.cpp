#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

// 2x2 matrix
struct Matrix {
    ll a[2][2];
};

// Multiply two 2x2 matrices
Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    memset(C.a, 0, sizeof(C.a));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Fast exponentiation of matrix
Matrix matrix_power(Matrix base, long long exp) {
    // Identity matrix
    Matrix result;
    result.a[0][0] = 1; result.a[0][1] = 0;
    result.a[1][0] = 0; result.a[1][1] = 1;

    while (exp > 0) {
        if (exp & 1)
            result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    Matrix M;
    M.a[0][0] = 1; M.a[0][1] = 1;
    M.a[1][0] = 1; M.a[1][1] = 0;

    Matrix Mn = matrix_power(M, n - 1);

    // S(1) = [1, 0]
    ll Fn = (Mn.a[0][0] * 1 + Mn.a[0][1] * 0) % MOD;
    cout << Fn << "\n";

    return 0;
}

