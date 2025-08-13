#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

vector<int> sieve(MAX + 1, 0);

void precompute() {
    for(int i=0; i<=MAX; ++i) {
        sieve[i] = i;
    }

    for(int i=2; i<=MAX; ++i) {
        if(sieve[i] == i) { 
            sieve[i] = i-1;
            for(int j=2*i; j<=MAX; j += i) { 
                sieve[j] = (sieve[j]/i)*(i-1);
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

    while(t--) {
        int n;
        cin >> n;
        cout << sieve[n] << '\n'; 
    }

    return 0;
}