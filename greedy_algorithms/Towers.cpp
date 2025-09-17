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

    vector<int> list;

    for(int i=0; i<n; ++i) {
    	int idx = upper_bound(list.begin(), list.end(), arr[i]) - list.begin();

    	if(idx == list.size()) {
    		list.push_back(arr[i]);
    	} else {
    		list[idx] = arr[i];
    	}
    }

    cout << list.size() << '\n';

    return 0;
}