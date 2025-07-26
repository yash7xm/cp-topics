#include <bits/stdc++.h>
using namespace std;

typedef long double ld;


bool isPossible(const vector<ld>& positions, const vector<ld>& speeds, ld time) {
    ld left = -1e18, right = 1e18;

    for (int i = 0; i < positions.size(); ++i) {
        ld currentLeft = positions[i] - speeds[i] * time;
        ld currentRight = positions[i] + speeds[i] * time;

        left = max(left, currentLeft);
        right = min(right, currentRight);
        
        if (left > right) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ld> positions(n);
    vector<ld> speeds(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> speeds[i];
    }

    ld lo = 0.0;
    ld hi = 1e18;
    for (int i = 0; i < 100; ++i) {
      	ld mid = (lo + hi) / 2;
        if (isPossible(positions, speeds, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(12) << hi << endl;

    return 0;
}