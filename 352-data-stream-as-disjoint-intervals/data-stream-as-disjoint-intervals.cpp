class SummaryRanges {
public:
    set<pair<int,int>> ranges;
    SummaryRanges() {
        ranges.insert(make_pair(-2, -2));
    }
    
    void addNum(int value) {
        auto range = make_pair(value, value);
        auto it = ranges.upper_bound(range);
        if(it != ranges.end() && value >= it->first && value <= it->second) {
            return;
        }
        it--;
        if(value >= it->first && value <= it->second) {
            return;
        }
        
        if(it->second == value - 1) {
            range.first = it->first;
            it = ranges.erase(it);
        }
        else{
            it++;
        }

        if(it != ranges.end() && it->first == value + 1) {
            range.second = it->second;
            ranges.erase(it);
        }

        ranges.insert(range);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for(auto it = next(ranges.begin()); it != ranges.end(); it++) {
            ret.push_back({it->first, it->second});
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