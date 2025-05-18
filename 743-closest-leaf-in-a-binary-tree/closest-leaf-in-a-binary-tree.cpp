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
    map<int, int> closestLeaf;
    map<int, int> dist;
    map<int, int> depth;
    map<int, bool> isAncestor;
    void dfs(TreeNode* u) {
        if(u->left == nullptr && u->right == nullptr) {
            closestLeaf[u->val] = u->val;
            dist[u->val] = 0;
            return;
        }
        dist[u->val] = INT_MAX;
    
        if(u->left != nullptr) {
            depth[u->left->val] = 1 + depth[u->val];
            dfs(u->left);
            dist[u->val] = 1 + dist[u->left->val];
            closestLeaf[u->val] = closestLeaf[u->left->val];
            isAncestor[u->val] |= isAncestor[u->left->val];
        }
        
        if(u->right != nullptr){
            depth[u->right->val] = 1 + depth[u->val];
            dfs(u->right);
            isAncestor[u->val] |= isAncestor[u->right->val];
            if(1 + dist[u->right->val] < dist[u->val]) {
                dist[u->val] = 1 + dist[u->right->val];
                closestLeaf[u->val] = closestLeaf[u->right->val];
            }
        }
    }

    pair<int,int> findAns(TreeNode* u) {
        auto ret = make_pair(depth[k] - depth[u->val] + dist[u->val], closestLeaf[u->val]);

        // cout << depth[k] - depth[u->val] + dist[u->val] << endl;
        
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