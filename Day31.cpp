//Day 31
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
    TreeNode *prev=NULL,*first=NULL,*second=NULL;
    void dfs(TreeNode *root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        if(first==NULL and (prev==NULL || prev->val>=root->val)){
            first=prev;
        }
        if(first!=NULL and prev->val>=root->val){
            second = root;
        }
        prev=root;
        dfs(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val,second->val);
    }
};
