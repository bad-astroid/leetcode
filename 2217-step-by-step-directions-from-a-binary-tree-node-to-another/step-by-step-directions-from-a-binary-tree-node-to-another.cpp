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
    bool dfs(TreeNode* u, int dest, vector<TreeNode*>& ancestors) {
        if(u == nullptr) return false;
        // cout << u->val << endl;
        if(u->val == dest) {
            ancestors.push_back(u);
            return true;
        }

        if(dfs(u->left, dest, ancestors)) {
            ancestors.push_back(u);
            return true;
        }

        if(dfs(u->right, dest, ancestors)) {
            ancestors.push_back(u);
            return true;
        }

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string ret = "";
        vector<TreeNode*> pathToStart, pathToDest;
        dfs(root, startValue, pathToStart);
        dfs(root, destValue, pathToDest);

        reverse(pathToStart.begin(), pathToStart.end());
        reverse(pathToDest.begin(), pathToDest.end());

        // for(auto u : pathToDest) {
        //     cout << u->val << endl;
        // }
        int lca = 0;
        for(int i = 0; i < min((int)pathToDest.size(), (int)pathToStart.size()); ++i) {
            if(pathToDest[i]->val != pathToStart[i]->val) break;
            lca = i;
        }
        for(int i = lca+1; i < pathToStart.size(); ++i) {
            ret += 'U';
        }

        for(int i = lca+1; i < pathToDest.size(); ++i) {
            if(pathToDest[i-1]->left == pathToDest[i]) ret += 'L';
            else ret += 'R';
        }
        
        return ret;
    }
};