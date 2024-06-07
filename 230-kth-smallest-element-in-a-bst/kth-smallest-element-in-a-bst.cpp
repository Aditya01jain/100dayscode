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
    void find(TreeNode* root, int k, priority_queue<int>& q){
        if(root==NULL){
            return;
        }
        find(root->left,k,q);
        if(q.size()<k){
            q.push(root->val);
        }else{
            if(root->val<q.top()){
                q.pop();
                q.push(root->val);
            }
        }
        find(root->right,k,q);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> q;
        find(root,k,q);
        return q.top();
    }
};