class Solution {
public:
    struct Node{
        vector<int> nxt = vector<int>(10, -1);
        int fr = 0;
    };
    vector<Node> trie = vector<Node>(1, Node());
    void insert(string s) {
        int u = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(trie[u].nxt[s[i] - '0'] == -1) {
                trie[u].nxt[s[i] - '0'] = trie.size();
                trie.push_back(Node());
            }

            u = trie[u].nxt[s[i] - '0'];
            trie[u].fr++;
        }
    }
    int find(string s) {
        int u = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(trie[u].nxt[s[i] - '0'] == -1) {
                return i;
            }
            u = trie[u].nxt[s[i] - '0'];
        }
        return s.size();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(auto a : arr1) {
            insert(to_string(a));
        }
        // to_string(num).length()
        int ret = 0;
        for(auto a : arr2) {
            string s = to_string(a);
            ret = max(ret, find(s));
        }  

        return ret;      
    }
};