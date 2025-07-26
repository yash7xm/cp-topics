#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

bool check(vector<int>& a, vector<int>& b, ld x, int k) {
    priority_queue<ld, vector<ld>, greater<ld>> pq;

    for (int i = 0; i < a.size(); ++i) {
        ld val = a[i] - x * b[i];
        pq.push(val);
        if (pq.size() > k) pq.pop();  // remove smallest, keeping largest k
    }

    ld sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum >= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> brr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i] >> brr[i];
    }

    ld lo = 0.0, hi = 1e6;

    while(hi - lo > 1e-6) {
    	ld mid = lo + (hi - lo) / 2.0;
    	if(check(arr, brr, mid, k)) {
    		lo = mid;
    	} else {
    		hi = mid;
    	}
    }

    cout << fixed << setprecision(10) << lo << endl;

    return 0;
}