class Solution {
public:
    int solve(int i, int j, vector<int> &nums){
        if(i == j) return nums[i];
        int takeleft = nums[i] - solve(i+1, j, nums);
        int takeright = nums[j] - solve(i, j-1, nums);

        return max(takeleft, takeright);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(0, n-1, nums);
        if(ans >= 0){
            return true;
        }
        return false;
    }
};