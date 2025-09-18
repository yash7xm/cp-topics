#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int m;
    cin >> m;

    vector<long long> usb, ps2;

    for (int i = 0; i < m; i++) {
        long long val;
        string type;
        cin >> val >> type;
        if (type == "USB") usb.push_back(val);
        else ps2.push_back(val);
    }

    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());

    long long total_cost = 0;
    long long total_used = 0;

    // Step 1: Fill USB-only
    for (int i = 0; i < a && i < (int)usb.size(); i++) {
        total_cost += usb[i];
        total_used++;
        usb[i] = -1; // mark as used
    }

    // Step 2: Fill PS/2-only
    for (int i = 0; i < b && i < (int)ps2.size(); i++) {
        total_cost += ps2[i];
        total_used++;
        ps2[i] = -1; // mark as used
    }

    // Step 3: Fill hybrid (c) with cheapest leftover
    vector<long long> leftover;
    for (auto x : usb) if (x != -1) leftover.push_back(x);
    for (auto x : ps2) if (x != -1) leftover.push_back(x);

    sort(leftover.begin(), leftover.end());

    for (int i = 0; i < c && i < (int)leftover.size(); i++) {
        total_cost += leftover[i];
        total_used++;
    }

    cout << total_used << " " << total_cost << "\n";
    return 0;
}
