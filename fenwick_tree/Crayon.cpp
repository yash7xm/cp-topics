#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, int v) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    int query(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    int rangeQuery(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<tuple<char, long long, long long>> ops;
    ops.reserve(N);

    vector<long long> coords;   // for coordinate compression

    for (int i = 0; i < N; i++) {
        char type;
        cin >> type;
        if (type == 'D') {
            long long L, R;
            cin >> L >> R;
            ops.emplace_back(type, L, R);
            coords.push_back(L);
            coords.push_back(R);
        } else if (type == 'Q') {
            long long L, R;
            cin >> L >> R;
            ops.emplace_back(type, L, R);
            coords.push_back(L);
            coords.push_back(R);
        } else { // C
            long long idx;
            cin >> idx;
            ops.emplace_back(type, idx, 0);
        }
    }

    // Coordinate compression
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    auto getId = [&](long long x) {
        return int(lower_bound(coords.begin(), coords.end(), x) - coords.begin()) + 1;
    };

    int M = coords.size();
    Fenwick bitStart(M), bitEnd(M);

    // store added segments so we can delete by index
    vector<pair<int,int>> added;  // (compressed L, compressed R)
    added.reserve(N + 1);

    int addCount = 0;

    for (auto &[type, x, y] : ops) {
        if (type == 'D') {
            int L = getId(x);
            int R = getId(y);

            bitStart.update(L, +1);
            bitEnd.update(R, +1);

            added.push_back({L, R});
            addCount++;
        }
        else if (type == 'C') {
            int idx = int(x) - 1; // 0-based
            auto [L, R] = added[idx];

            bitStart.update(L, -1);
            bitEnd.update(R, -1);
        }
        else { // Q
            int L = getId(x);
            int R = getId(y);

            int startsBeforeR = bitStart.query(R);
            int endsBeforeL  = bitEnd.query(L - 1);

            cout << startsBeforeR - endsBeforeL << "\n";
        }
    }

    return 0;
}

