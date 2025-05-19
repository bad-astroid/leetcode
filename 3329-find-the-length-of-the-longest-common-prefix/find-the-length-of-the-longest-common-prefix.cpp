class Solution {
public:
    struct Node{
        vector<Node*> nxt = vector<Node*>(10, nullptr);
    };
    Node* root = new Node() ;
    void insert(string s) {
        Node* u = root;
        for(int i = 0; i < s.size(); ++i) {
            if(u->nxt[s[i] - '0'] == nullptr) {
                u->nxt[s[i] - '0'] = new Node();
            }

            u = u->nxt[s[i] - '0'];
        }
    }
    int find(string s) {
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
        for(auto a : arr1) {
            insert(to_string(a));
        }

        int ret = 0;
        for(auto a : arr2) {
            string s = to_string(a);
            ret = max(ret, find(s));
        }  

        return ret;      
    }
};