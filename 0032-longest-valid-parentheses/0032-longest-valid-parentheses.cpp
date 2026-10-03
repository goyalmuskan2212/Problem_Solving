class Solution {
public:
    // Solution 1. t.c->O(n^3) and s.c->O(n)
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
    // Solution 2. t.c->O(n) and s.c->O(n)
    /*int longestValidParentheses(string s) {
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
    }*/
    // Solution 3. t.c->O(n) and s.c->O(1)
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int maxi = 0;
        int left = 0;
        int right = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') left++;
            else right++;
            if(left == right) maxi = max(maxi, 2 * right);
            if(right > left){
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(') left++;
            else right++;
            if(left == right) maxi = max(maxi, 2*left);
            if(left > right){
                left = 0;
                right = 0;
            }
        }
        return maxi;
    }
};