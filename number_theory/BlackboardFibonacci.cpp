#include <bits/stdc++.h>
using namespace std;

bool can_reach(int a, int b, int n) {
    while (a && b) {
        if (a >= b) {
            int quotient = a / b;
            n -= quotient;
            a %= b;
        } else {
            int quotient = b / a;
            if (quotient > 1 && b % a == 0) {
                quotient--;
            }
            n -= quotient;
            b -= a * quotient;
        }
    }
    return min(a, b) == 0 && max(a, b) == 1 && n == 0;
}

string build_sequence(int a, int b) {
    if (a == 0 && b == 1) return "";
    if (a >= b) return build_sequence(a - b, b) + "T";
    return build_sequence(a, b - a) + "B";
}

int count_mistakes(const string& s) {
    int mistakes = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) mistakes++;
    }
    return mistakes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, r;
    cin >> n >> r;
    
    pair<int, string> result = {n + 1, ""};
    
    for (int x = 1; x <= r; x++) {
        if (can_reach(x, r, n)) {
            string seq = build_sequence(x, r);
            int mistakes = count_mistakes(seq);
            if (mistakes < result.first) {
                result = {mistakes, seq};
            }
        }
        if (can_reach(r, x, n)) {
            string seq = build_sequence(r, x);
            int mistakes = count_mistakes(seq);
            if (mistakes < result.first) {
                result = {mistakes, seq};
            }
        }
    }
    
    if (result.first > n) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << result.first << "\n" << result.second << "\n";
    }
    
    return 0;
}