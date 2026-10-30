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
    int goodNodeCount{};

    void dfs(TreeNode* root, int maxVal) {
        if (root == nullptr) return;

        if (root->val >= maxVal) {
            maxVal = root->val;
            goodNodeCount++;
        }

        dfs(root->right, maxVal);
        dfs(root->left, maxVal);

    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return -1;
        goodNodeCount = 0;
        dfs(root, root->val);
        return goodNodeCount;

    }
};
