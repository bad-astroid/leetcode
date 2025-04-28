class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size(), K = 500 * N;
        vector<vector<int>> ans(N + 1, vector<int>(K + 1, 0));
        ans[0][0] = 1;
        int robbed = 0;
        for(int i = 1; i <= N; ++i) {
            for(int k = 1; k <= K; ++k) {
                ans[i][k] |= ans[i-1][k];
                if(nums[i - 1] == k) {
                    ans[i][k] = 1;
                }
                if(nums[i - 1] <= k && i >= 2) {
                    ans[i][k] |= ans[i - 2][k - nums[i - 1]];
                }

                if(nums[i - 1] <= k && i >= 3) {
                    ans[i][k] |= ans[i - 3][k - nums[i - 1]];
                }

                if(ans[i][k]) {
                    robbed = max(robbed, k);
                }
            }
        }


        // for(int i = 1; i <= N; ++i) {
        //     for(int k = 1; k <= 5; ++k) {
        //         printf("ans[%d][%d] = %d\n", i, k, ans[i][k]);
        //     }
        // }

        return robbed;        
    }
};