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
    void solve(TreeNode* root, map<int, pair<int, int>>& mp, int h, int l) {
        if (root == NULL) return;
        if (mp.find(l) == mp.end() || mp[l].first <= h) {
            mp[l] = {h, root->val};
        }
        solve(root->left, mp, h + 1, l + 1);
        solve(root->right, mp, h + 1, l + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int, pair<int, int>> mp;
        solve(root, mp, 0, 0);
        for (auto i : mp) {
            ans.push_back(i.second.second);
        }
        return ans;
    }
};
