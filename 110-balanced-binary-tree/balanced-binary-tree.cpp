class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1) return false;

        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);

        return leftBalanced && rightBalanced;
    }

private:
    int height(TreeNode* node) {
        if (node == NULL) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
};
