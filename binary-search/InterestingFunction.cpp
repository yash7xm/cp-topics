#include <bits/stdc++.h>
using namespace std;

// void solve() {
// 	int l,r;
// 	cin >> l >> r;

// 	long long cnt = 0;

// 	while(r > 0) {
// 		cnt += r-l;
// 		l /= 10;
// 		r /= 10;
// 	}

// 	cout << cnt << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while(t--) {
//     	solve();
//     }
//     return 0;
// }


// Function to calculate number of changed digits from 1 to x
long long f(long long x) {
    long long res = 0;
    while (x > 0) {
        res += x;
        x /= 10;
    }
    return res;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        cout << f(r) - f(l) << "\n";
    }
    return 0;
}