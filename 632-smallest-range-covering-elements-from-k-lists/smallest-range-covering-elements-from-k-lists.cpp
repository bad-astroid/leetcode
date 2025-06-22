class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ret = {(int)-1e6, (int)1e6};
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums[i].size(); ++j) {
                v.push_back({nums[i][j], i});
            }
        }

        sort(v.begin(), v.end());
        vector<int> fr(nums.size());
        int listCnt = 0;
        for(int r = 0, l = 0; r < v.size(); ++r) {
            if(++fr[v[r].second] == 1) listCnt++;

            while(listCnt == nums.size()) {
                if(v[r].first - v[l].first < ret[1] - ret[0]) {
                    ret[1] = v[r].first;
                    ret[0] = v[l].first;
                }

                if (--fr[v[l++].second] == 0) listCnt--;
            }
            
        }

        return ret;
    }
};