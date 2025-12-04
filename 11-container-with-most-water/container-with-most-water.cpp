class Solution {
public:
    int _maxArea(vector<int> height) {
        vector<pair<int,int>> maxs;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            auto h = height[i];
            if(maxs.empty()) {
                maxs.push_back({h, i});
                continue;
            }

            vector<pair<int,int>>::iterator leftmostMaxIt = lower_bound(maxs.begin(), maxs.end(), make_pair(h, 0));
            if(leftmostMaxIt != maxs.end()) {
                auto X = i - leftmostMaxIt->second;
                ans = max(ans, X * h);
            }

            if(maxs.back().first < h) maxs.push_back({h, i});
        }

        return ans;
    }
    int maxArea(vector<int>& height) {
        auto reversed = height;
        reverse(reversed.begin(), reversed.end());
        return max(_maxArea(height), _maxArea(reversed));
    }
};