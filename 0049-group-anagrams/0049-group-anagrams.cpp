class Solution {
public:
    bool anagramCheck(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        int freq[26] = {0};
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<int> hash(n, 0);
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(hash[i] == 1) continue;
            vector<string> ds;
            ds.push_back(strs[i]);
            hash[i] = 1;
            for(int j=i+1; j<n; j++){
                if(hash[j] == 0){
                    if(anagramCheck(strs[i], strs[j])){
                        ds.push_back(strs[j]);
                        hash[j] = 1;
                    }
                }
            }
            ans.push_back(ds);
        }
        return ans;
    }
};