#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

vector<int> sieve(MAX + 1, 0);

void precompute() {
	for(int i=2; i <= MAX; ++i) {
		if(sieve[i] == 0) {
			for(int j = i; j <= MAX; j += i) {
				if(sieve[j] == 0) sieve[j] = i;
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;

	int N = n;

	long long res = 1;
	while(sieve[n] != 0) {
		int alpha = 1;
		int spf = sieve[n];
		while(n % spf == 0) {
			alpha++;
			n /= spf;
		}

		res *= (pow(spf, alpha) - 1)/(spf - 1);
	}

	cout << res - N << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;

    while(t--) {
    	solve();
    }

    return 0;
}