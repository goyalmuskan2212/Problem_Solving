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
    bool leaf(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        return false;
    }
    int solve(TreeNode* root, int &sum){
        if(root == NULL){
            return 0;
        }
        if(root->left != NULL && leaf(root->left)) sum += root->left->val; 
        int left = solve(root->left, sum);
        int right = solve(root->right, sum);
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};