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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL) return NULL;
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            if(level == depth-1){
                for(int i=0; i<size; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    TreeNode* oldLeft = node->left;
                    TreeNode* oldRight = node->right;
                    TreeNode* leftNode = new TreeNode(val);
                    TreeNode* rightNode = new TreeNode(val);
                    node->left = leftNode;
                    node->right = rightNode;
                    leftNode->left = oldLeft;
                    rightNode->right = oldRight;
                }
                break;
            }
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};