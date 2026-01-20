#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

struct Matrix {
    int n;
    vector<vector<ll>> a;

    Matrix(int n) : n(n) {
        a.assign(n, vector<ll>(n, INF));
    }
};

// Min-plus matrix multiplication
Matrix multiply(const Matrix &A, const Matrix &B) {
    int n = A.n;
    Matrix C(n);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A.a[i][k] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (B.a[k][j] == INF) continue;
                C.a[i][j] = min(C.a[i][j],
                                A.a[i][k] + B.a[k][j]);
            }
        }
    }
    return C;
}

// Fast exponentiation
Matrix matrix_power(Matrix base, long long exp) {
    int n = base.n;
    Matrix result(n);

    // Identity matrix (0 on diagonal, INF elsewhere)
    for (int i = 0; i < n; i++)
        result.a[i][i] = 0;

    while (exp > 0) {
        if (exp & 1)
            result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    Matrix M(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        M.a[u][v] = min(M.a[u][v], w);
    }

    Matrix Mk = matrix_power(M, k);

    ll ans = Mk.a[0][n - 1];
    if (ans >= INF / 2) ans = -1;

    cout << ans << "\n";
    return 0;
}

