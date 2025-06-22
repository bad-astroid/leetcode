class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret, frP(26, 0), frS(26, 0);
        int anagramCharCount = 0;
        if(p.size() > s.size()) {
            return ret;
        }
        for(auto x : p) {
            frP[x - 'a']++;
        }

        for(int i = 0; i < (int)p.size(); ++i) {
            if (++frS[s[i] - 'a'] == frP[s[i] - 'a']) anagramCharCount += frP[s[i] - 'a'];
            else if (frS[s[i] - 'a'] == frP[s[i] - 'a'] + 1) anagramCharCount -= frP[s[i] - 'a'];
            if(anagramCharCount == p.size()) {
                ret.push_back(0);
            }
        }

        for(int i = p.size(), j = 0; i < (int)s.size(); ++i, ++j) {
            if (--frS[s[j] - 'a'] == frP[s[j] - 'a']) anagramCharCount += frP[s[j] - 'a'];
            else if (frS[s[j] - 'a'] == frP[s[j] - 'a'] - 1) anagramCharCount -= frP[s[j] - 'a'];

            if (++frS[s[i] - 'a'] == frP[s[i] - 'a']) anagramCharCount += frP[s[i] - 'a'];
            else if (frS[s[i] - 'a'] == frP[s[i] - 'a'] + 1) anagramCharCount -= frP[s[i] - 'a'];

            if(anagramCharCount == p.size()) {
                ret.push_back(j + 1);
            }
        }


        return ret;
    }
};