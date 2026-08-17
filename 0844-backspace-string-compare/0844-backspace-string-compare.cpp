class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();
        string newS = "";
        string newT = "";
        for(int i=0; i<n; i++){
            if(newS.size() == 0 && s[i] == '#') continue;
            if(s[i] != '#'){
                newS += s[i];
            }
            else{
                newS.pop_back();
            }
        }
        for(int i=0; i<m; i++){
            if(newT.size() == 0 && t[i] == '#') continue;
            if(t[i] != '#'){
                newT += t[i];
            }
            else{
                newT.pop_back();
            }
        }
        if(newS == newT) return true;
        return false;
    }
};