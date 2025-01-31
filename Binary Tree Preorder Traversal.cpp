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
void preorder(TreeNode* root, vector<int>& pre) {
        if(root == NULL) return;

        pre.push_back(root->val);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        preorder(root, pre);
        return pre;
    }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     stack<TreeNode*> stack;
    //     TreeNode* curr = root;
    //     while (curr != NULL || !stack.empty()) {
    //         while (curr != NULL) {
    //             stack.push(curr);
    //             curr = curr->left;
    //         }
    //         curr = stack.top();
    //         stack.pop();
    //         res.push_back(curr->val);
    //         curr = curr->right;
    //     }
    //     return res;
    // }
};
