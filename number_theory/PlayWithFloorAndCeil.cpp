#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

tuple<ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) {
        return {1, 0};
    }
    auto [p1, q1] = extended_gcd(b, a % b);
    ll p = q1;
    ll q = p1 - (a / b) * q1;
    return {p, q};
}

void solve() {
	int x, k;
    cin >> x >> k;

    if (x % k == 0) {
        ll a = x / k;
        cout << "0 " << k << endl;
    } else {
        ll a = x / k;
        ll b = (x + k - 1) / k; // This gives ceil(x/k)
        // Since a and b are consecutive, gcd(a,b)=1.
        auto [p0, q0] = extended_gcd(a, b);
        ll p = x * p0;
        ll q = x * q0;
        cout << p << " " << q << endl;
    }
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