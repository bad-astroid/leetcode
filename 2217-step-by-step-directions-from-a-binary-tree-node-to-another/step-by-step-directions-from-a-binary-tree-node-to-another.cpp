/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool traverse(TreeNode* u, vector<pair<int,char>>& path, int dest, char direction = '*') {
        if(u == nullptr) {
            return false;
        }

        if(u->val == dest) {
            path.push_back(make_pair(u->val, direction));
            return true;
        }

        if (traverse(u->left, path, dest, 'L')) {
            path.push_back(make_pair(u->val, direction));
            return true;
        }

        if (traverse(u->right, path, dest, 'R')) {
            path.push_back(make_pair(u->val, direction));
            return true;
        }

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<pair<int,char>> pathToStart, pathToDest;
        traverse(root, pathToStart, startValue);
        traverse(root, pathToDest, destValue);
        reverse(pathToStart.begin(), pathToStart.end());
        reverse(pathToDest.begin(), pathToDest.end());

        // for(auto u : pathToStart) {
        //     cout << u.first << " ";
        // }
        // puts("");

        // for(auto u : pathToDest) {
        //     cout << u.first << " ";
        // }
        // puts("");

        int lca = 0;
        for(int i = 0; i < min(pathToStart.size(), pathToDest.size()); ++i) {
            if(pathToStart[i].first == pathToDest[i].first) {
                lca = i + 1;
            }
        }
        // if(lca + 1 == min(pathToStart.size(), pathToDest.size())) {
        //     lca++;
        // }
        string ans = "";

        for(int i = lca; i < pathToStart.size(); ++i) {
            ans += 'U';
        }

        for(int i = lca; i < pathToDest.size(); ++i) {
            ans += pathToDest[i].second;
        }

        return ans;
    }
};