class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // column -> {row, value}
        map<int, vector<pair<int, int>>> mp;

        // node, row, column
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty()) {

            auto [node, row, col] = q.front();
            q.pop();

            mp[col].push_back({row, node->val});

            if (node->left) {
                q.push({node->left, row + 1, col - 1});
            }

            if (node->right) {
                q.push({node->right, row + 1, col + 1});
            }
        }

        vector<vector<int>> ans;

        for (auto &it : mp) {

            auto &v = it.second;

            // First sort by row,
            // then by value if row is same
            sort(v.begin(), v.end());

            vector<int> temp;

            for (auto &[row, value] : v) {
                temp.push_back(value);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};