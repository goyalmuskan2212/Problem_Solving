class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n-1;
        while(i<=j){
            ans += (nums[j]-nums[i]);
            i++;
            j--;
        }
        return (int)ans;
    }
};