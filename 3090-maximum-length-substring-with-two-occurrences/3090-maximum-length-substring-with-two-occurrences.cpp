class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        int i = 0;
        int j = 0;
        unordered_map<int , int> mpp;
        while(j < n){
            mpp[s[j]-'a']++;
            while(mpp[s[j]-'a'] > 2){
                if(mpp[s[i]-'a'] == 1) mpp.erase(s[i]-'a');
                else mpp[s[i]-'a']--;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};