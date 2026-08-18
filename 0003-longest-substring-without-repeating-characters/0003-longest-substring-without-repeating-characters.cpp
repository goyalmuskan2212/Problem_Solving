class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0;
        int j=0;
        map<char, int> mpp;
        int maxi = 0;
        while(j < n){
            while(mpp.find(s[j]) != mpp.end()){
                if(mpp[s[i]] == 1){
                    mpp.erase(s[i]);
                }
                else mpp[s[i]]--;
                i++;
            }
            mpp[s[j]]++;
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};