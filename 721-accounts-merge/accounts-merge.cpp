class Solution {
public:
    vector<int> par;
    int findp(int u) {
        if(u == par[u]) return u;
        return par[u] = findp(par[u]);
    }
    void join(int u, int v) {
        u = findp(u);
        v = findp(v);

        if (v < u) swap(u, v);

        par[v] = u;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ret;
        map<string, int> accountId;
        par.assign(accounts.size(), 0);
        for(int j = 0; j < accounts.size(); ++j) {
            par[j] = j;
            vector<string> &account = accounts[j];
            for(int i = 1; i < account.size(); ++i) {
                string &email = account[i];

                if(accountId.contains(email)) {
                    join(accountId[email], j);
                }

                accountId[email] = findp(j);
            }
        }

        map<int, vector<string>> mp;
        for(int j = 0; j < accounts.size(); ++j) {
            auto &account = accounts[j];
            int setId = findp(j);
            
            if(!mp.contains(setId)) {
                mp[setId] = { account[0] };
            }

            for(int i = 1; i < account.size(); ++i) {
                mp[setId].push_back(account[i]);
            }
        }

        for(auto it : mp) {
            auto account = it.second;
            sort(account.begin() + 1, account.end());
            account.erase(unique(account.begin(), account.end()), account.end());
            ret.push_back(account);
        }

        return ret;
    }
};