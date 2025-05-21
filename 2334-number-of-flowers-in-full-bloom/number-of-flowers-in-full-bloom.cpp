class Solution {
public:
    int compressNums(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> nums;
        for(auto flower : flowers) {
            nums.push_back(flower[0]);
            nums.push_back(flower[1]);
            nums.push_back(flower[1]+1);
        }
        for(auto person : people) {
            nums.push_back(person);
        }
        sort(nums.begin(), nums.end());

        for(auto& flower : flowers) {
            for(auto& time : flower) {
                int at = lower_bound(nums.begin(), nums.end(), time) - nums.begin();
                time = at;
            }
        }
        for(auto& person : people) {
            int at = lower_bound(nums.begin(), nums.end(), person) - nums.begin();
            person = at;
        }
        return nums.size();
    }
    vector<int> fullBloomFlowers(vector<vector<int>> flowers, vector<int> people) {
        vector<int> ret;
        int N = compressNums(flowers, people);
        vector<int> fullBloomFlowersAt(N, 0);
        for(auto flower : flowers) {
            fullBloomFlowersAt[flower[0]] += 1;
            fullBloomFlowersAt[flower[1]+1] -= 1;
        }
        for(int i = 1; i < N; ++i) {
            fullBloomFlowersAt[i] += fullBloomFlowersAt[i - 1];
        }

        for(auto personTime : people) {
            ret.push_back(fullBloomFlowersAt[personTime]);
        }
        
        return ret;
    }
};