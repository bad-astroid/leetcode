class LRUCache {
public:
    list<pair<int,int>> cache;
    map<int, list<pair<int,int>>::iterator> mp;
    int capacity;
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    
    int get(int key) {
        // for(auto x : cache) cout << x.first << ' '; puts("");
        if(!mp.contains(key)) {
            return -1;
        }
        updatePlace(key);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.contains(key)) {
            remove(key);
        }

        if (cache.size() == capacity) {
            remove(cache.begin()->first);
        }
        
        addKVP(key, value);
    }

    void remove(int key) {
        auto it = mp[key];
        mp.erase(key);
        cache.erase(it);
    }

    void updatePlace(int key) {
        int value = mp[key]->second;
        remove(key);
        addKVP(key, value);
    }

    void addKVP(int key, int value) {
        cache.push_back(make_pair(key, value));
        auto it = cache.end();
        it--;
        mp[key] = it;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */