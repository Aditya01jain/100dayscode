class Solution {
public:
    int result = 0;
    vector<int> DFS(TreeNode* root, int distance) {
        if (!root->left && !root->right)
            return {1};
        vector<int> Left =
            (root->left ? DFS(root->left, distance) : vector<int>());
        vector<int> Right =
            (root->right ? DFS(root->right, distance) : vector<int>());
        for (int i : Left)
            for (int j : Right)
                result += (i + j <= distance);
        if (Right.size() > Left.size())
            swap(Left, Right);
        Left.insert(Left.end(), Right.begin(), Right.end());
        for (int& i : Left)
            i++;
        return Left;
    }
    int countPairs(TreeNode* root, int distance) {
        DFS(root, distance);
        return result;
    }
};