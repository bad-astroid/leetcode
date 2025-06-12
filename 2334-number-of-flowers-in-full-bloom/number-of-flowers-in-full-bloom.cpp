class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> flowers, vector<int> people) {
        vector<int> ret, starts, ends;
        for(auto flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for(auto person : people) {
            int startBeforeCount = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            int endBeforeCount = lower_bound(ends.begin(), ends.end(), person) - ends.begin();
            ret.push_back(startBeforeCount - endBeforeCount);
            cout << person << ' ' << startBeforeCount << ' ' << endBeforeCount << endl;
        }
        return ret;
    }
};