#include <bits/stdc++.h>
using namespace std;

int main() {
    int Y, W;
    cin >> Y >> W;

    int M = max(Y, W);
    int num = 7 - M;
    int den = 6;

    int g = __gcd(num, den);
    num /= g;
    den /= g;

    cout << num << "/" << den << "\n";
    return 0;
}

