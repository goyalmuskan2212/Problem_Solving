class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        int prevCnt = 0;
        string ans = "";
        for(int i=0; i<n; i++){
            prevCnt = cnt;
            if(s[i] == '(') cnt++;
            else cnt--;
            if(i != 0 && cnt != 0 && prevCnt != 0) ans += s[i];
        }
        return ans;
    }
};