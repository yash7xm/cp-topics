class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int MOD = 1337;
        if (a == 1) return 1;
        
        // Euler's totient function for MOD = 1337 = 7 * 191
        // phi(1337) = (7-1)*(191-1) = 6 * 190 = 1140
        const int phi = 1140;
        
        // Compute the exponent b mod phi
        int exponent = 0;
        for (int digit : b) {
            exponent = (exponent * 10 + digit) % phi;
        }
        
        // Since a and MOD might not be coprime, and if exponent is 0 after mod phi, we need to use exponent = phi
        // But C++'s pow(a, exponent, MOD) doesn't handle negative exponents, so we need to ensure exponent is positive
        if (exponent == 0) {
            exponent = phi;
        }
        
        // Compute a^exponent mod MOD
        int result = 1;
        a %= MOD;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * a) % MOD;
            }
            a = (a * a) % MOD;
            exponent /= 2;
        }
        
        return result;
    }
};