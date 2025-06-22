class SummaryRanges {
public:
    map<int,int> mp;
    SummaryRanges() {

    }

    void addNum(int value) {
        pair<int,int> interval = make_pair(value, value);
        auto it = mp.upper_bound(value);

        if(it != mp.end() && it->first - 1 == value) {
            interval.second = it->second;
            it = mp.erase(it);
        }

        if(it != mp.begin()) {
            it--;
            if(value <= it->second) return;

            if(value == it->second + 1) {
                interval.first = it->first;
                mp.erase(it);
            }
        }

        mp[interval.first] = interval.second;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for(auto x : mp) {
            ret.push_back({x.first, x.second});
        }
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */