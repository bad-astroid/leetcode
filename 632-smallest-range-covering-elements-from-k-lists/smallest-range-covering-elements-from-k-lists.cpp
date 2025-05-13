class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> allNums;
        for (int i = 0; i < nums.size(); ++i) {
            for(auto num : nums[i]) {
                allNums.push_back(make_pair(num, i));
            }
        }

        sort(allNums.begin(), allNums.end());

        int l = 0, ansL = -1e5 - 1, ansR = 1e5 + 1, cnt = 0;
        vector<int> fr(nums.size(), 0);
        for(int r = 0; r < allNums.size(); ++r) {
            if(++fr[allNums[r].second] == 1) {
                cnt++;
            }

            while(cnt == nums.size()) {
                if(allNums[r].first - allNums[l].first < ansR - ansL) {
                    ansR = allNums[r].first;
                    ansL = allNums[l].first;
                }

                if(--fr[allNums[l++].second] == 0) {
                    cnt--;
                }
            }
        }

        return {ansL, ansR};
    }
};