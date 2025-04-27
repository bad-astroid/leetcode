class Solution {
public:
    void dfs(vector<int> &nums, int at) {
        int to = nums[at - 1];
        nums[at - 1] = -1;
        if(to <= 0) {
            return;
        }
        dfs(nums, to);
    }
    int firstMissingPositive(vector<int>& nums) {    
        for(auto &num : nums) {
            if(num < 0 || num > nums.size()) {
                num = 0;
            }
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] <= 0) {
                continue;
            }
            dfs(nums, nums[i]);
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != -1) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};