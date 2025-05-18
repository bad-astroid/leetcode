class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,bool> prefixExists;
        for(auto a : arr1) {
            while(a) {
                prefixExists[a] = true;
                a /= 10;
            }
        }
        // to_string(num).length()
        int ret = 0;
        for(auto a : arr2) {
            while(a) {
                if(prefixExists[a] == true) {
                    ret = max(ret, static_cast<int>(log10(a) + 1));
                }

                a /= 10;
            }
        }  

        return ret;      
    }
};