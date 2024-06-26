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
    vector<TreeNode*>array;
    TreeNode* balanceBST(TreeNode* root) 
    {
        inorderTraversal(root);
        return sortedArrayToBst(0,array.size()-1);
    }
     void inorderTraversal(TreeNode* root)
    {
        if(root==NULL)
            return ;
        inorderTraversal(root->left);
        array.push_back(root);
        inorderTraversal(root->right);
        
    }
    TreeNode* sortedArrayToBst(int start,int end)
    {
        if(start>end)
            return NULL;
        int mid = (start+end)/2;
        TreeNode* root = array[mid];
        root->left = sortedArrayToBst(start,mid-1);
        root->right = sortedArrayToBst(mid+1,end);
        return root;
        

    }
   
    
};