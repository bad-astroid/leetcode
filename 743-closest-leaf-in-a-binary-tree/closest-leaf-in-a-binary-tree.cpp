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
    int k;
    unordered_map<int, pair<int,int>> closestLeaf;
    unordered_map<int, int> depth;
    unordered_map<int, bool> isAncestor;
    void dfs(TreeNode* u) {
        if(u->left == nullptr && u->right == nullptr) {
            closestLeaf[u->val] = make_pair(0, u->val);
            return;
        }

        closestLeaf[u->val] = make_pair(INT_MAX, INT_MAX);
    
        if(u->left != nullptr) {
            depth[u->left->val] = 1 + depth[u->val];
            dfs(u->left);
            closestLeaf[u->val] = make_pair(closestLeaf[u->left->val].first + 1, closestLeaf[u->left->val].second);
            isAncestor[u->val] |= isAncestor[u->left->val];
        }
        
        if(u->right != nullptr){
            depth[u->right->val] = 1 + depth[u->val];
            dfs(u->right);
            isAncestor[u->val] |= isAncestor[u->right->val];
            closestLeaf[u->val] = min(closestLeaf[u->val], make_pair(closestLeaf[u->right->val].first + 1, closestLeaf[u->right->val].second));
        }
    }

    pair<int,int> findAns(TreeNode* u) {
        auto ret = make_pair(depth[k] - depth[u->val] + closestLeaf[u->val].first, closestLeaf[u->val].second);
        
        if(u->left != nullptr && isAncestor[u->left->val]) {
            ret = min(ret, findAns(u->left));
        }

        if(u->right != nullptr && isAncestor[u->right->val]) {
            ret = min(ret, findAns(u->right));
        }

        return ret;
    }

    int findClosestLeaf(TreeNode* root, int _k) {
        k = _k;
        isAncestor[k] = true;
        dfs(root);
        return findAns(root).second;
    }
};