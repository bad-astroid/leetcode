class SnapshotArray {
public:
    int snapIdNow;
    vector<vector<pair<int,int>>> a;
    SnapshotArray(int length) {
        snapIdNow = 0;
        a = vector<vector<pair<int,int>>> (length, vector<pair<int,int>> (1, make_pair(snapIdNow, 0)));
    }
    
    void set(int index, int val) {
        if(a[index].back().first == snapIdNow) {
            a[index].back().second = val;
            return;
        }

        a[index].push_back(make_pair(snapIdNow, val));
    }
    
    int snap() {
        return snapIdNow++;
    }
    
    int get(int index, int snap_id) {
        int at = lower_bound(a[index].begin(), a[index].end(), make_pair(snap_id + 1, 0)) - a[index].begin() - 1;
        // cout << at << endl;
        return a[index][at].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */