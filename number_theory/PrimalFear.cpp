#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
vector<bool> is_prime(MAX + 1, true);
vector<int> primal_fear_primes(MAX + 1, 0);

bool has_zero(int num) {
    while (num > 0) {
        if (num % 10 == 0) return true;
        num /= 10;
    }
    return false;
}

bool is_truncatable_prime(int num) {
    if (has_zero(num)) return false;
    
    int temp = num;
    int divisor = 1;
    while (divisor * 10 <= temp) {
        divisor *= 10;
    }
    
    while (temp > 0) {
        if (!is_prime[temp]) return false;
        temp %= divisor;
        divisor /= 10;
    }
    
    return true;
}

void precompute() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    int count = 0;
    for (int i = 2; i <= MAX; ++i) {
        if (is_prime[i] && is_truncatable_prime(i)) {
            count++;
        }
        primal_fear_primes[i] = count;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << primal_fear_primes[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}