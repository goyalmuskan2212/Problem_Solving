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
    void preOrder(TreeNode* root, vector<TreeNode*> &pre){
        if(!root) return;
        pre.push_back(root);
        preOrder(root->left, pre);
        preOrder(root->right, pre);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> pre;
        preOrder(root, pre);

        TreeNode* dummy = root;
        for(int i=1; i<pre.size(); i++){
            dummy->left = nullptr;
            dummy->right = pre[i];
            dummy = dummy->right;
        }
    }
};