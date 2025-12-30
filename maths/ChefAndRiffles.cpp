#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while(T--) {
        int N;
        long long K;
        cin >> N >> K;

        int half = N/2;

        // base permutation = riffle once
        vector<int> base(N+1);
        for(int i=1;i<=N;i++){
            if(i <= half) base[i] = 2*i - 1;
            else base[i] = 2*(i-half);
        }

        // identity permutation result
        vector<int> res(N+1);
        for(int i=1;i<=N;i++) res[i] = i;

        auto compose = [&](vector<int> &A, vector<int> &B){
            vector<int> C(N+1);
            for(int i=1;i<=N;i++)
                C[i] = A[B[i]];
            return C;
        };

        while(K > 0){
            if(K & 1)
                res = compose(res, base);   // res *= base
            base = compose(base, base);     // base *= base
            K >>= 1;
        }

        for(int i=1;i<=N;i++)
            cout << res[i] << " ";
        cout << '\n';
    }
}

