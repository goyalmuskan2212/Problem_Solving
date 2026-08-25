class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        int newK = k;
        while(mpp.find(k) != mpp.end()){
            k += newK;
        }
        return k;
    }
};