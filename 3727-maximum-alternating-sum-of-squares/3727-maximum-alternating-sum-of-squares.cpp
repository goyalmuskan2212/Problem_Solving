class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                nums[i] = nums[i]*(-1);
            }
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for(int i=0; i<n; i++){
            if(i<n/2){
                sum -= (long long)(nums[i]*nums[i]);
            }
            else{
                sum += (long long)(nums[i]*nums[i]);
            }
        }
        return sum;
    }
};