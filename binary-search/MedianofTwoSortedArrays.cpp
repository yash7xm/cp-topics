class Solution {
public:
    // Returns true if there are more than k elements <= x
    bool check(vector<int>& nums1, vector<int>& nums2, int k, int x) {
        int cnt = 0;
        cnt += upper_bound(nums1.begin(), nums1.end(), x) - nums1.begin();
        cnt += upper_bound(nums2.begin(), nums2.end(), x) - nums2.begin();
        return cnt >= k;
    }

    int kthElement(int k, vector<int>& nums1, vector<int>& nums2) {
        int lo = INT_MAX, hi = INT_MIN;

        if (!nums1.empty()) {
            lo = min(lo, nums1[0]);
            hi = max(hi, nums1.back());
        }
        if (!nums2.empty()) {
            lo = min(lo, nums2[0]);
            hi = max(hi, nums2.back());
        }

        // Binary search for the kth smallest element
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(nums1, nums2, k, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int total = n + m;

        if (total % 2 == 1) {
            return kthElement((total + 1) / 2, nums1, nums2);
        } else {
            int left = kthElement(total / 2, nums1, nums2);
            int right = kthElement(total / 2 + 1, nums1, nums2);
            return (left + right) / 2.0;
        }
    }
};
