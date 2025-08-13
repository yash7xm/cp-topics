#include <bits/stdc++.h>
using namespace std;

const int MAX = 5 * 1e6;

vector<int> phi(MAX + 1, 0);

void precompute() {
	for(int i=0; i<=MAX; ++i) {
		phi[i] = i;
	}

	for(int i=2; i<=MAX; ++i) {
		if(phi[i] == i) {
			phi[i] = i-1;
			for(int j=2*i; j<=MAX; j += i) {
				phi[j] = (phi[j]/i)*(i-1);
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    precompute();

    for(int c = 1; c <= t; ++c) {
    	int a, b;
    	cin >> a >> b;

    	long long sum = 0;
    	for(int i=a; i<=b; ++i) {
    		sum += phi[i] * phi[i];
    	}

    	cout << "Case " << c << ": " << sum << endl;
    }

    return 0;
}