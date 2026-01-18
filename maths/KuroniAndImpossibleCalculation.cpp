#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Pigeonhole principle:
    // If n > m, two numbers have same remainder mod m
    // => |ai - aj| ≡ 0 (mod m)
    // => whole product ≡ 0 (mod m)
    if (n > m) {
        cout << 0 << "\n";
        return 0;
    }

    long long ans = 1;

    // Safe brute force when n <= m
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diff = llabs(a[i] - a[j]);
            ans = (ans * (diff % m)) % m;
        }
    }

    cout << ans << "\n";
    return 0;
}

