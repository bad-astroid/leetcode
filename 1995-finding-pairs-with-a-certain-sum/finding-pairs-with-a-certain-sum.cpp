class FindSumPairs {
public:
    map<int,int> freq;
    vector<int> nums1, nums2;
    FindSumPairs(vector<int>& _nums1, vector<int>& _nums2) {
        nums1 = _nums1;
        nums2 = _nums2;
        for(auto num : nums2) {
            freq[num]++;
        }
    }
    
    void add(int index, int val) {
        freq[nums2[index]]--;
        nums2[index] += val;
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto num : nums1) {
            int rem = tot - num;
            ans += freq[rem];
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */