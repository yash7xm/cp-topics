#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

struct Matrix {
    ll a[2][2];
};

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

Matrix matrix_power(Matrix base, long long exp) {
    Matrix result;
    result.a[0][0] = 1; result.a[0][1] = 0;
    result.a[1][0] = 0; result.a[1][1] = 1;

    while (exp > 0) {
        if (exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    Matrix M;
    M.a[0][0] = 19; M.a[0][1] = 6;
    M.a[1][0] = 7;  M.a[1][1] = 20;

    Matrix Mn = matrix_power(M, n);

    // Initial state S(0) = [1, 0]
    ll happy = Mn.a[0][0];  // 19*1 + 6*0
    cout << happy << "\n";

    return 0;
}

