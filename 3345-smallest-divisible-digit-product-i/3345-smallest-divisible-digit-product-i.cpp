class Solution {
public:
    int solve(int n){
        string s = to_string(n);
        int product = 1;
        for(int i=0; i<s.size(); i++){
            product *= (s[i]-'0');
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        int product = solve(n);
        if(product % t == 0) return n;
        int ans = 0;
        while(product%t != 0){
            product = 1;
            product = solve(n);
            if(product%t == 0){
                ans = n;
                break;
            }
            n++;
        }
        return ans;
    }
};