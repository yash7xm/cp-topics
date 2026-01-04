#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, long long val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Fenwick fw(n);

    vector<long long> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // Build difference array in Fenwick Tree
    fw.update(1, A[1]);
    for (int i = 2; i <= n; i++) {
        fw.update(i, A[i] - A[i - 1]);
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            long long u;
            cin >> a >> b >> u;
            fw.update(a, u);
            if (b + 1 <= n) {
                fw.update(b + 1, -u);
            }
        } else {
            int k;
            cin >> k;
            cout << fw.query(k) << "\n";
        }
    }
}

