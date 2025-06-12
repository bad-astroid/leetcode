class Solution {
public:
    int n;
    string getString(string& s, pair<int,int> ans) {
        string ret = "";
        for(int i = ans.first; i <= ans.second; ++i) {
            ret += s[i];
        }
        return ret;
    }
    string longestPalindrome(string s) {
        pair<int,int> ans = make_pair(0,0);
        n = s.size();
        vector<vector<int>> dp = vector<vector<int>> (n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            if(i) {
                dp[i-1][i] = (s[i-1] == s[i]);
                if(dp[i-1][i]) {
                    ans = make_pair(i-1, i);
                }
            }
        }

        for(int len = 3; len <= n; ++len) {
            for(int l = 0, r = len - 1; r < n; ++r, ++l) {
                dp[l][r] = (dp[l+1][r-1] && (s[l] == s[r]));
                if(dp[l][r]) {
                    ans = make_pair(l, r);
                }
            }
        }

        return getString(s, ans);
    }
};