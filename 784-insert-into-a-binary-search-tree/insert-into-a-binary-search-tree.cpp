class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the root is null, create a new node and return it as the root
        if (root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode* current = root;
        TreeNode* parent = nullptr;

        // Traverse the tree to find the correct position for the new node
        while (current) {
            parent = current;
            if (val < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Create the new node
        TreeNode* newNode = new TreeNode(val);

        // Attach the new node to the correct parent node
        if (val < parent->val) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        // Return the original root of the tree
        return root;
    }
};
