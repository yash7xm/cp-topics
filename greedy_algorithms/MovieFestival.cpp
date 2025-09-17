#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
    	return a.second < b.second;
    });

    int cnt = 0, last_end = 0;

    for(auto &m : arr) {
    	if(m.first >= last_end) {
    		cnt++;
    		last_end= m.second;
    	}
    }

    cout << cnt << '\n';

    return 0;
}