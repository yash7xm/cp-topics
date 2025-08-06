#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> sieve(n+1, 0);

    for(int i=2; i <= n; ++i) {
    	if(sieve[i] == 0) {
    		for(int j=i; j<=n; j += i) {
    			sieve[j]++;
    		}
    	}
    }

    int count = 0;
    for(int i=2; i<=n; ++i) {
    	if(sieve[i] == 2) {
    		count++;
    	}
    }

    cout << count << endl;

    return 0;
}