class HitCounter {
public:
    vector<int> timeStamps;
    HitCounter() {
        timeStamps = vector<int>(0);
    }
    
    void hit(int timeStamp) {
        timeStamps.push_back(timeStamp);
    }
    
    int getHits(int timeStamp) {
        int fiveMinutesAgo = timeStamp - 300;
        int at = upper_bound(timeStamps.begin(), timeStamps.end(), fiveMinutesAgo) - timeStamps.begin();
        return timeStamps.size() - at;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */