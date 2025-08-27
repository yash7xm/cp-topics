#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

void solve() {
	ll n, k;
	cin >> n >> k;

	vector<ll> arr(n);
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	ll g = 0;
	for(int i=0; i<n; ++i) {
		g = gcd(g, arr[i] - arr[0]);
	}

	cout << (((k-arr[0]) % g == 0) ? "YES" : "NO") << endl;
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