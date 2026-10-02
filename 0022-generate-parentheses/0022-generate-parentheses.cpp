class Solution {
public:
    void helper(int open,int close, string &ds, int n, vector<string> &ans){
        if(ds.size() == (2*n)){
            ans.push_back(ds);
            return;
        }
        if(open < n){
            ds.push_back('(');
            helper(open+1, close, ds, n, ans);
            ds.pop_back();
        }
        if(close < open){
            ds.push_back(')');
            helper(open, close+1, ds, n, ans);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string ds = "";
        vector<string> ans;
        helper(0, 0, ds, n, ans);
        return ans;
    }
};