class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> hash(26, 0);
        for(int i=0; i<n; i++){
            hash[word[i] - 'a']++;
        }
        sort(hash.begin(), hash.end(), greater<int>());
        int ans = 0;
        for(int i=0; i<26; i++){
            if(i<8){
                ans += (hash[i]);
            }
            else if(i>=8 && i<16){
                ans += (hash[i]*2);
            }
            else if(i>=16 && i<24){
                ans += (hash[i]*3);
            }
            else{
                ans += (hash[i]*4);
            }
        }
        return ans;
        
    }
};