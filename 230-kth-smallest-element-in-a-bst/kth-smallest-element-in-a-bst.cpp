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
    void inorder(TreeNode* root,int& k,int & ans){
        if(root==NULL) return;
        if(root->left) inorder(root->left,k,ans);
        k--;
        if(k==0) ans=root->val;
        if(root->right) inorder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans =0;
        inorder(root,k,ans);
        return ans;
    }
};