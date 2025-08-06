#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> sieve(1e7 + 1, true);

    if(n == 1) {
    	cout << 2 << endl;
    	return 0;
    }

    for(int i=4; i <= sieve.size(); i += 2) {
    	sieve[i] = false;
    }

    for(int i=3; i*i <= sieve.size(); i += 2) {
    	if(sieve[i]) {
    		for(int j=i*i; j <= sieve.size(); j += 2 * i) {
    			sieve[j] = false;
    		}
    	}
    }

    n--;
    for(int i=3; i <= sieve.size(); i += 2) {
    	if(sieve[i]) {
    		n--;
    	}

    	if(n == 0) {
    		cout << i << endl;
    		break;
    	}
    }

    return 0;
}