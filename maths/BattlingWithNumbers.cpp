#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    int M;
    cin >> M;
    vector<int> C(M), D(M);
    for (int i = 0; i < M; i++) cin >> C[i];
    for (int i = 0; i < M; i++) cin >> D[i];

    long long ans = 1;

    int i = 0, j = 0;
    while (i < N || j < M) {
        if (j == M || (i < N && A[i] < C[j])) {
            // Prime only in X
            // D = 0, B > 0 → contributes 2
            ans = (ans * 2) % MOD;
            i++;
        } else if (i == N || C[j] < A[i]) {
            // Prime in Y but not in X → impossible
            cout << 0 << "\n";
            return 0;
        } else {
            // Same prime
            int b = B[i];
            int d = D[j];
            if (d > b) {
                cout << 0 << "\n";
                return 0;
            }
            if (d < b) {
                ans = (ans * 2) % MOD;
            }
            // else d == b → multiply by 1
            i++;
            j++;
        }
    }

    cout << ans << "\n";
    return 0;
}

