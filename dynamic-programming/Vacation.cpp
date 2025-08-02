#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> arr(3, vector<int>(n));
    for(int j=0; j<n; ++j) {
    	cin >> arr[0][j] >> arr[1][j] >> arr[2][j];
    }

    long long a = arr[0][0];
    long long b = arr[1][0];
    long long c = arr[2][0];

    for(int j=1; j<n; ++j) {
    	long long na = arr[0][j] + max(b, c);
    	long long nb = arr[1][j] + max(a,c);
    	long long nc = arr[2][j] + max(a,b);

    	a = na;
    	b = nb;
    	c = nc;
    }

   	long long res = max(a, max(b, c));

   	cout << res << endl;

    return 0;
}