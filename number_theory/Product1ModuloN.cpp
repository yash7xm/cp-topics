#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coprimes;
    for (int k = 1; k < n; ++k) {
        if (gcd(k, n) == 1) {
            coprimes.push_back(k);
        }
    }
    
    long long product = 1;
    for (int num : coprimes) {
        product = (product * num) % n;
    }
    
    vector<int> result;
    if (product == 1) {
        result = coprimes;
    } else {
        for (int num : coprimes) {
            if (num != product) {
                result.push_back(num);
            }
        }
    }
    
    cout << result.size() << '\n';
    for (int num : result) {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}