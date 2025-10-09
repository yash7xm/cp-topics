#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'A']++;

    int oddCount = 0;
    char oddChar = 0;

    for (int i = 0; i < 26; ++i) {
        if (cnt[i] % 2 != 0) {
            oddCount++;
            oddChar = 'A' + i;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string left = "", mid = "";

    for (int i = 0; i < 26; ++i) {
        if (cnt[i] % 2 != 0) mid += string(cnt[i], 'A' + i);
        else left += string(cnt[i] / 2, 'A' + i);
    }

    if (oddCount == 1) {
        int i = oddChar - 'A';
        left += string(cnt[i] / 2, oddChar);
        mid = string(cnt[i] % 2, oddChar);
    }

    string right = left;
    reverse(right.begin(), right.end());

    cout << left << mid << right << '\n';
    return 0;
}
