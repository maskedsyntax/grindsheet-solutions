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
private:
    vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        util(root);
        return ans;
    }

    void util(TreeNode* root) {
        if (root == nullptr) return;
        util(root->left);
        util(root->right);
        ans.push_back(root->val);
    }
};