#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

vector<bool> sieve(MAX + 1, true);

void precompute() {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); // Call the precompute function to fill the sieve

    int n;
    cin >> n;

    vector<long long> arr(n);
    for (long long &a : arr) cin >> a;

    for (long long num : arr) {
        long long root = sqrtl(num); // Use sqrtl for long long to avoid precision issues
        if (root * root == num && root <= MAX && sieve[root]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}