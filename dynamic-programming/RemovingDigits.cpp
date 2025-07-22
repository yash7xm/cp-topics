#include <bits/stdc++.h>
using namespace std;

int getLargestDigit(int num) {
    int largest = 0;
    while (num > 0) {
        int digit = num % 10;
        largest = max(largest, digit);
        num /= 10;
    }
    return largest;
}

int main() {
    int n;
    cin >> n;
    
    int steps = 0;
    while (n > 0) {
        int digit = getLargestDigit(n);
        n -= digit;
        steps++;
    }
    
    cout << steps << endl;
    
    return 0;
}