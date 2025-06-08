class TimeMap {
public:
    unordered_map<string, map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        map<int, string>::iterator it = mp[key].upper_bound(timestamp);
        if(mp[key].empty() || it == mp[key].begin()) {
            return "";
        }
        it--;
        // for(auto x : mp[key]) {
        //     cout << x.first << ' ' << x.second << endl;
        // }
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */