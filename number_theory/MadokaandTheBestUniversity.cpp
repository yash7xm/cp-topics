#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

vector<int> phi;
vector<vector<int>> divisors;

void precompute(int n) {
    phi.assign(n + 1, 0);
    for (int i = 0; i <= n; ++i) phi[i] = i;
    for (int i = 2; i <= n; ++i) {
        if (phi[i] == i) { 
        	phi[i] = i-1;               
            for (int j = 2 * i; j <= n; j += i)
                phi[j] = (phi[j] / i) * (i - 1);
        }
    }

    divisors.assign(n + 1, {});
    for (int d = 1; d <= n; ++d) {
        for (int m = d; m <= n; m += d) {
            divisors[m].push_back(d);
        }
    }
}


ll gcdll(ll a, ll b) {
    return b == 0 ? a : gcdll(b, a % b);
}

ll lcmll(ll a, ll b) {
    return a / gcdll(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    precompute(n);

    ll ans = 0;
    for (int c = 1; c <= n - 2; ++c) {
        int k = n - c;                         	
        for (int d : divisors[k]) {            	
            if (d == k) continue;              	
            int cnt = phi[k / d];              
            ll l = lcmll(c, d);       		  
            ans += (l * cnt) % MOD;
        }
    }

    cout << (ans % MOD) << '\n';
    return 0;
}
