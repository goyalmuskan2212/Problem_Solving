class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                break;
            }
            if(i == n-1) return 0;
        }
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini, nums[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += (nums[i]-mini);
        }
        return ans;
    }
};