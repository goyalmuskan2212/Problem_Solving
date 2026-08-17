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
    void inorder(TreeNode* root, int key, vector<int> &inor){
        if(root == NULL) return;
        inorder(root->left, key, inor);
        if(root->val != key) inor.push_back(root->val);
        inorder(root->right, key, inor);
    }
    TreeNode* buildBst(vector<int> &nums, int left, int right){
        if(left > right) return NULL;
        int mid = left + ((right-left)/2);
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBst(nums, left, mid-1);
        node->right = buildBst(nums, mid+1, right);
        return  node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> inor;
        inorder(root, key, inor);
        return buildBst(inor, 0, inor.size()-1);
    }
};