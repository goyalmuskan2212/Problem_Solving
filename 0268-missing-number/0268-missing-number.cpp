class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actualSum = 0;
        for(int i=0; i<=n; i++){
            actualSum += i;
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        } 
        return actualSum - sum;
    }
};