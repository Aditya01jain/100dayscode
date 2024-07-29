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
    void solve(TreeNode* root, map<int, map<int, vector<int>>>& mp, int i, int l) {
        if (root == NULL) return;
        mp[i][l].push_back(root->val);
        solve(root->left, mp, i - 1, l + 1);
        solve(root->right, mp, i + 1, l + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        if (root == NULL) return {};
        solve(root, mp, 0, 0);
        vector<vector<int>> ans;
        for (auto it1 : mp) {
            vector<int> col;
            for (auto it2 : it1.second) {
                sort(it2.second.begin(), it2.second.end());
                col.insert(col.end(), it2.second.begin(), it2.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
