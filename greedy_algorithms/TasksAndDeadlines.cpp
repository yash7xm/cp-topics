#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<long long, long long>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second; // duration, deadline
    }
    
    // Sort by duration
    sort(tasks.begin(), tasks.end());

    long long time = 0, reward = 0;
    for (auto &task : tasks) {
        time += task.first;                  // add duration
        reward += (task.second - time);      // deadline - completion time
    }

    cout << reward << "\n";

    return 0;
}