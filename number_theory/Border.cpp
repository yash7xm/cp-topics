#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    int g = 0;
    for(int i=0; i<n; ++i) {
    	int t;
    	cin >> t;
    	g = gcd(g, t);
    }

    // set<int> ans;
    // for(int i=0; i<k; ++i) {
    // 	ans.insert((1LL * g * i) % k);
    // }

    // cout << ans.size() << endl;
    // for(int d : ans) {
    // 	cout << d << " ";
    // }

    int g0 = gcd(g, k);
    int count = k / g0;
    
    cout << count << "\n";
    for (int i = 0; i < count; i++) {
        cout << i * g0 << " ";
    }

    return 0;
}