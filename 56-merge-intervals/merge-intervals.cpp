class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int left = intervals[0][0], right = intervals[0][1];
        for(auto interval : intervals) {
            if(interval[0] > right) {
                if(right != -1) ans.push_back({left, right});
                left = interval[0];
                right = interval[1];
                continue;
            }
            right = max(right, interval[1]);
        }

        ans.push_back({left, right});

        return ans;
    }
};