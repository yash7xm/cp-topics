#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int k;
    cin >> k;

    while(k--) {
    	int l, r;
    	cin >> l >> r;

    	int ub = upper_bound(arr.begin(), arr.end(), r) - arr.begin();
    	int lb = lower_bound(arr.begin(), arr.end(), l) - arr.begin();

    	cout << ub - lb << " ";
    }
    cout << endl;

    return 0;
}