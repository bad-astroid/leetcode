class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<vector<int>> ans(n, vector<int>(2, 0));
        ans[0][1] = nums[0];
        ans[0][0] = 0;
        ans[1][0] = nums[1];
        ans[1][1] = ans[0][1];
        for(int i = 2; i < n; ++i) {
            if(i == n - 1){
                ans[i][1] = ans[i - 1][1];
                ans[i][0] = max(ans[i - 1][0], ans[i - 2][0] + nums[i]);
                continue;
            }
            ans[i][1] = max(ans[i - 1][1], ans[i - 2][1] + nums[i]);
            ans[i][0] = max(ans[i - 1][0], ans[i - 2][0] + nums[i]);
        }

        return max(ans[n - 1][0], ans[n - 1][1]);        
    }
};