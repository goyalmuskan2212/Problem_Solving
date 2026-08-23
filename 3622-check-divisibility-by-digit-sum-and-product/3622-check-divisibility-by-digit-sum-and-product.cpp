class Solution {
public:
    int sumDig(string s){
        int sum = 0;
        for(int i=0; i<s.size(); i++){
            sum += (s[i]-'0');
        }
        return sum;
    }
    int product(string s){
        int ans = 1;
        for(int i=0; i<s.size(); i++){
            ans *= (s[i]-'0');
        }
        return ans;
    }
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int prod = product(s);
        int su = sumDig(s);
        int res = prod + su;
        if(n % res == 0) return true;
        return false;
    }
};