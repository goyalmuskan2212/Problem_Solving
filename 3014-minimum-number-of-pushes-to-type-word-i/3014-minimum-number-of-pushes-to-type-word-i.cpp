class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        if(n <= 8){
            ans = n;
        }
        else if(n > 8 && n <= 16){
            int rem = n-8;
            ans = 8 + (rem*2);
        }
        else if(n > 16 && n <= 24){
            int rem = n-16;
            ans = 8 + (16) + (rem*3);
        }
        else{
            int rem = n-24;
            ans = 8 + 16 + 24 + (rem*4);
        }
        return ans;
    }
};