class Solution {
public:
    int findPivot(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int n = nums.size();    
        int ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < nums[0]) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }

    int binarySearch(vector<int>& nums, int lo, int hi, int target) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

        if (pivot == 0) {
            // no rotation
            return binarySearch(nums, 0, n - 1, target);
        }

        // Decide which part to search
        if (target >= nums[0]) {
            return binarySearch(nums, 0, pivot - 1, target);
        } else {
            return binarySearch(nums, pivot, n - 1, target);
        }
    }
};
