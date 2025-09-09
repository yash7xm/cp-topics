#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int l = 0, r = n-1;
    int res = 0;

    while(l <= r) {
    	if(arr[l] + arr[r] <= x) {
    		l++;
    	}
    	
    	r--;
    	res++;
    }

    cout << res << endl;

    return 0;
}