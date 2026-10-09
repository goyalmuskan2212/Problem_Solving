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
    int solve(TreeNode* root, unordered_map<int, int> &mpp, int sum){
        if(root == NULL) return 0;
        
        int left = solve(root->left, mpp, sum);
        int right = solve(root->right, mpp, sum);

        sum = left + right + root->val;
        mpp[sum]++;

        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        solve(root, mpp, 0);
        int maxi = 0;
        for(auto it : mpp){
            maxi = max(maxi, it.second);
        }
        if(maxi == 0) return ans;
        for(auto it : mpp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};