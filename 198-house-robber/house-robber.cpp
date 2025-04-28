class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> ans(n);
        ans[0] = nums[0];
        ans[1] = max(nums[1], ans[0]);
        for(int i = 2; i < n; ++i) {
            ans[i] = max(ans[i - 1], ans[i - 2] + nums[i]);
        }

        return ans[n - 1];        
    }
};