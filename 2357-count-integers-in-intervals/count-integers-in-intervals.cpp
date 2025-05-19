class CountIntervals {
public:
    int cnt = 0;
    set<pair<int,int>> segments;
    CountIntervals() {
        
    }
    bool canMerge(pair<int,int> p1, pair<int,int> p2) {
        if(p2 < p1) swap(p1, p2);
        return p1.second >= p2.first;
    }
    pair<int,int> merge(pair<int,int> p1, pair<int,int> p2) {
        // cout << p2.first << ' ' << p2.second << endl;
        if(canMerge(p1, p2)) {
            cnt -= p2.second - p2.first + 1;
            segments.erase(segments.find(p2));
            p1.first = min(p1.first, p2.first);
            p1.second = max(p1.second, p2.second);
        }
        return p1;
    }
    void add(int left, int right) {
        auto it = segments.lower_bound(make_pair(left,right));

        if(it != segments.begin()) {
            it--;
        }

        while(it != segments.end()) {
            if(it->first > right) break;
            auto res = merge(make_pair(left,right), *it);
            left = res.first;
            right = res.second;
            it++;
        }

        segments.insert(make_pair(left,right));
        cnt += right - left + 1;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */