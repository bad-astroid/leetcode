class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> st;
        int ans = 1e9;
        for(int i = x; i < nums.size(); ++i) {
            st.insert(nums[i-x]);
            auto it = st.lower_bound(nums[i]);
            if(it != st.end()) {
                ans = min(ans, *it - nums[i]);
            }
            if(it != st.begin()) {
                it--;
                ans = min(ans, nums[i] - *it);
            }

        }

        return ans;
    }
};