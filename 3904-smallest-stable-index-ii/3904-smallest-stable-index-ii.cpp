class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxx(n, -1);
        vector<int> minn(n, -1);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[n-i-1]);
            maxx[i] = maxi;
            minn[n-i-1] = mini;
        }
        for(int i=0; i<n; i++){
            if(maxx[i] - minn[i] <= k){
                return i;
            }
        }
        return -1;
    }
};