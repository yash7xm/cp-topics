#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long total = n * (n + 1) / 2;
    if (total % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    long long target = total / 2;
    
    vector<int> set1, set2;
    long long sum1 = 0;

    for (int i = n; i >= 1; --i) {
        if (sum1 + i <= target) {
            set1.push_back(i);
            sum1 += i;
        } else {
            set2.push_back(i);
        }
    }

    cout << set1.size() << "\n";
    for (int x : set1) cout << x << " ";
    cout << "\n";

    cout << set2.size() << "\n";
    for (int x : set2) cout << x << " ";
    cout << "\n";
}
