class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();
        int incCount = 0, decCount = 0;
        int  mono = 0;
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            if(a[i] == a[i-1]) { 
                if (mono == -1 && incCount && decCount) {
                    ans = max(ans, incCount + decCount + 1);
                }
                mono = 0;
                incCount = decCount = 0;
                continue;
            }

            if(a[i] > a[i-1]) {
                if (mono == -1 && incCount && decCount) {
                    ans = max(ans, incCount + decCount + 1);
                }
                if(mono != 1) incCount = 0;
                incCount++;
                decCount = 0;
                mono = 1;
                continue;
            }

            if(a[i] < a[i-1]) {
                // mono = 0  -> decCounbt = 1;
                // mono = 1 -> decCount = 1
                // mono = -1 -> decCount++;
                if(mono != -1) decCount = 0;
                decCount++;
                mono = -1;
            }
        }

        if (mono == -1 && incCount && decCount) {
            ans = max(ans, incCount + decCount + 1);
        }

        return ans;
    }
};