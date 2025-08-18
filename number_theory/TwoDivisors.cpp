#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

void solve() {
	ll a,b;
	cin >> a >> b;

	ll res;

	if(b % a == 0) {
		res = b * (b / a);
	} else {
		res = a * (b / gcd(a, b));
	}

	cout << res << endl;
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