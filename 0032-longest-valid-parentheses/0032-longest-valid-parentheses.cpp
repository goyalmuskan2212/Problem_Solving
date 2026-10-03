class Solution {
public:
    /*bool valid(string s){
        int n = s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    if(st.top() == '('){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string str = s.substr(i, j-i+1);
                int m = str.size();
                if(valid(str)){
                    maxi = max(maxi, m);
                }
            }
        }
        return maxi;
    }*/
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int maxi = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxi = max(maxi, i-st.top());
                }
            }
        }
        return maxi;
    }
};