class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) total += x;
        
        if (total % k != 0) return false;
        int target = total / k;

        // Optimization: sort descending (prunes faster)
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;

        int N = 1 << n;
        vector<int> dp(N, -1);
        dp[0] = 0;

        for (int mask = 0; mask < N; mask++) {
            if (dp[mask] == -1) continue;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;

                if (dp[mask] + nums[i] <= target) {
                    int newMask = mask | (1 << i);
                    int newSum = (dp[mask] + nums[i]) % target;

                    dp[newMask] = newSum;
                }
            }
        }

        return dp[N - 1] == 0;
    }
};

