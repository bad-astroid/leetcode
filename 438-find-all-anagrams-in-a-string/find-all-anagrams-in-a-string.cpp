class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) {
            return vector<int>(0);
        }
        vector<int> pFr(26, 0), sFr(26), ret;
        for(int i = 0; i < p.size(); ++i) {
            ++pFr[p[i] - 'a'];
        }
        int cnt = 0;
        for(int i = 0; i < (int)p.size(); ++i) {
            ++sFr[s[i] - 'a'];
            if(sFr[s[i] - 'a'] == pFr[s[i] - 'a']) {
                cnt += pFr[s[i] - 'a'];
            }

            if(sFr[s[i] - 'a'] == pFr[s[i] - 'a'] + 1) {
                cnt -= pFr[s[i] - 'a'];
            }
        }

        if(cnt == p.size()) {
            ret.push_back(0);
        }

        for(int r = (int)p.size(), l = 0; r < s.size(); ++r){
            --sFr[s[l] - 'a'];
            if(sFr[s[l] - 'a'] == pFr[s[l] - 'a']) {
                cnt +=  pFr[s[l] - 'a'];
            }
            if(sFr[s[l] - 'a'] == pFr[s[l] - 'a'] - 1) {
                cnt -=  pFr[s[l] - 'a'];
            }
            ++l;

            ++sFr[s[r] - 'a'];
            if(sFr[s[r] - 'a'] == pFr[s[r] - 'a']) {
                cnt += pFr[s[r] - 'a'];
            }
            if(sFr[s[r] - 'a'] == pFr[s[r] - 'a'] + 1) {
                cnt -= pFr[s[r] - 'a'];
            }
            
            // cout << l << ' ' << cnt << endl;
            if(cnt == p.size()) {
                ret.push_back(l);
            }
        }



        return ret;
    }
};