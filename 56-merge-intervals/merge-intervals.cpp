class Solution {
public:
    bool static compare(vector<int>& v1, vector<int> &v2) {
        auto p1 = make_pair(v1[0], v1[1]);
        auto p2 = make_pair(v2[0], v2[1]);
        return p1 < p2;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
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