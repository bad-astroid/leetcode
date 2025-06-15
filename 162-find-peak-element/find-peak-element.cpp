class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            int before = (m == 0 ? -INT_MAX : nums[m - 1]);
            int after = (m == n - 1 ? -INT_MAX : nums[m + 1]);
            if (nums[m] >= before && nums[m] >= after) return m;
            if(after >= nums[m]) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};