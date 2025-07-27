#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    unordered_map<int, vector<int>> map;

    for(int i=0; i<n; ++i) {
    	map[arr[i]].push_back(i);
    }

    while(q--) {
    	int l, r, x;
    	cin >> l >> r >> x;

    	const vector<int>& indices = map[x];

    	int left = lower_bound(indices.begin(), indices.end(), l) - indices.begin();
        int right = lower_bound(indices.begin(), indices.end(), r) - indices.begin();

        cout << (right - left) << '\n';
    }

    return 0;
}