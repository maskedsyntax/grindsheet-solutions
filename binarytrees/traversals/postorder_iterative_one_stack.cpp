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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;
        stack<TreeNode*> st;
        
        while(!st.empty() || curr != nullptr) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* top = st.top();
                if (top->right != nullptr && lastVisited != top->right) {
                    curr = top->right;
                }
                else {
                    ans.push_back(top->val);
                    lastVisited = top;
                    st.pop();
                }
            }
        }
        
        return ans;
    }
};