class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]+1){
                sum += nums[i];
            }
            else break;
        }

        unordered_set<int> unique(nums.begin(), nums.end());

        int ans = sum;
        while(unique.count(ans)){
            ans++;
        }
        return ans;
    }
};