#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll extend_gcd(ll a, ll b, ll& x, ll& y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll gcd = extend_gcd(b, a%b, x1, y1);

	x = y1;
	y = x1 - (a/b)*y1;

	return gcd;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b;

    while(cin >> a >> b) {
    	ll x,y;
    	ll g = extend_gcd(a,b,x,y);

    	cout << x << " " << y << " " << g << endl;
    }

    return 0;
}