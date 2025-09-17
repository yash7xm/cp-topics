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
    vector<int> set1, set2;

    if (n % 4 == 0) {
        // Case: n divisible by 4
        for (int i = 1; i <= n; i += 4) {
            set1.push_back(i);
            set1.push_back(i + 3);
            set2.push_back(i + 1);
            set2.push_back(i + 2);
        }
    } else if (n % 4 == 3) {
        // Case: n mod 4 == 3
        set1.push_back(1);
        set1.push_back(2);
        set2.push_back(3);
        for (int i = 4; i <= n; i += 4) {
            set1.push_back(i);
            set1.push_back(i + 3);
            set2.push_back(i + 1);
            set2.push_back(i + 2);
        }
    }

    cout << set1.size() << "\n";
    for (int x : set1) cout << x << " ";
    cout << "\n";

    cout << set2.size() << "\n";
    for (int x : set2) cout << x << " ";
    cout << "\n";

    return 0;
}
