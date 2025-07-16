#include <bits/stdc++.h>
using namespace std;

// Check if it's possible to paint all boards within `maxTimeAllowed` using `k` painters
bool isPossible(vector<int>& boards, int maxTimeAllowed, int k) {
    int paintersUsed = 1;
    int currentSum = 0;

    for (int length : boards) {
        if (currentSum + length <= maxTimeAllowed) {
            currentSum += length;
        } else {
            // Assign to next painter
            paintersUsed++;
            currentSum = length;

            // If more painters are required than available, return false
            if (paintersUsed > k) return false;
        }
    }

    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> boards(n);
    for (int i = 0; i < n; ++i) {
        cin >> boards[i];
    }

    // Define binary search boundaries
    int low = *max_element(boards.begin(), boards.end()); // At least one board must be painted whole
    int high = accumulate(boards.begin(), boards.end(), 0); // One painter paints all

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, mid, k)) {
            result = mid;      // Try a better (smaller) maximum
            high = mid - 1;
        } else {
            low = mid + 1;     // Need to allow more time
        }
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
