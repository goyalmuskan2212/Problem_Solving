class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> last(26);

        for(int i=0; i<n; i++){
            last[s[i]-'a'] = i;
        }

        vector<bool> inSt(26, false);
        string st;
        
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(inSt[ch - 'a']) continue;

            while(!st.empty() && st.back()>ch && last[st.back()-'a'] > i){
                inSt[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            inSt[ch - 'a'] = true;
        }
        return st;
    }
};