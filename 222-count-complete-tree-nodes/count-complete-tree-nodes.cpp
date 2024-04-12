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
    void count(TreeNode* root, int &c) {
    if (root == NULL) {
        return;
    }
    c++;
    count(root->left, c);
    count(root->right, c);
}

int countNodes(TreeNode* root) {
    int c = 0;
    count(root, c);
    return c;
}
};