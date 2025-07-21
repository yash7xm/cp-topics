#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

bool canMeet(vector<int>& pos, vector<int>& time, ld T) {
	ld left = -1e18, right = 1e18;

	for(int i=0; i<pos.size(); ++i) {
		if(time[i] > T) return false;

		left = max(left, pos[i] - (T - time[i]));
		right = min(right, pos[i] + (T - time[i]));
	}

	return left <= right;
}

void solve() {
	int n;
	cin >> n;

	vector<int> pos(n);
	for(int& x : pos) cin >> x;

	vector<int> time(n);
	for(int&t : time) cin >> t;

    ld lo = 0;
	ld hi = 2e14;

	while(hi - lo > 1e-6) {
		ld mid = lo + (hi - lo) / 2;
		if(canMeet(pos, time, mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}

	ld left = -1e18, right = 1e18;
	ld T = hi;

	for(int i=0; i<pos.size(); ++i) {
		left = max(left, pos[i] - (T - time[i]));
		right = min(right, pos[i] + (T - time[i]));
	}

	cout << fixed << setprecision(10) << (left + right) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
    	solve();
    }

    return 0;
}