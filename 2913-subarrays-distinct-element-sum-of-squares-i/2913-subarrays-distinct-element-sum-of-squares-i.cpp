class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            unordered_map<int, int> mpp;
            for(int j=i; j<n; j++){
                mpp[nums[j]]++;
                int dis = (mpp.size()*mpp.size());
                sum += dis;
            }
        }
        return sum;
    }
};