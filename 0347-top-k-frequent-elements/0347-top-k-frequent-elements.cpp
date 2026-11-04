class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        int maxi = 0;
        for(auto it : mpp) {
            maxi = max(maxi, it.second);
        }
        vector<vector<int>> freq(maxi + 1);
        for(auto it : mpp) {
            freq[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = maxi; i >= 1; i--) {
            for(auto num : freq[i]) {
                ans.push_back(num);

                if(ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};