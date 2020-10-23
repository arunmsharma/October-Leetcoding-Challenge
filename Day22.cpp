//Day 22
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
    void dfs(TreeNode *root,int level,int &leaflevel){
        if(root==NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL){
            leaflevel=min(leaflevel,level);
        }
        dfs(root->left,level+1,leaflevel);
        dfs(root->right,level+1,leaflevel);
    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leaflevel=INT_MAX;
        dfs(root,1,leaflevel);
        return leaflevel;
    }
};
