class Solution {
public:
    struct Node {
        Node* nxt[10] = {};
    };
    Node* root = new Node();
    void add(string s) {
        Node* u = root;
        for(int i = 0; i < s.size(); ++i) {
            if(u->nxt[s[i] - '0'] == nullptr) {
                u->nxt[s[i] - '0'] = new Node();
            }
            u = u->nxt[s[i] - '0'];
        }
    }

    int findLcp(string s) {
        Node* u = root;
        for(int i = 0; i < s.size(); ++i) {
            if(u->nxt[s[i] - '0'] == nullptr) {
                return i;
            }
            u = u->nxt[s[i] - '0'];
        }

        return s.size();
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        for(auto x : arr1) {
            add(to_string(x));
        }

        for(auto x : arr2) {
            res = max(res, findLcp(to_string(x)));
        }

        return res;
    }
};