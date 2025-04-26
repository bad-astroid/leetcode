class Solution {
public:
    void addToDq(deque<pair<int,int>> &dq, int num, int index) {
        while(!dq.empty() && dq.back().first < num) {
            dq.pop_back();
        }

        dq.push_back({num, index});
    }

    void popDqFront(deque<pair<int,int>> &dq, int index) {
        if(dq.front().second <= index) {
            dq.pop_front();
        }
    }

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), ans = 1;
        deque<pair<int,int>> mn, mx;
        
        addToDq(mx, nums[0], 0);
        addToDq(mn, nums[0] * -1, 0);
        
        for(int l = 0, r = 1; r < n; ++r) {
            addToDq(mx, nums[r], r);
            addToDq(mn, nums[r] * -1, r);

            while(mx.front().first + mn.front().first > limit) {
                popDqFront(mx, l);
                popDqFront(mn, l);
                l++;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};