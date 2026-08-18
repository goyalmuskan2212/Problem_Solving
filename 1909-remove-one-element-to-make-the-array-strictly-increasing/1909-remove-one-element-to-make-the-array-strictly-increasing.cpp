class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int removed = 0;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= prev) {
                removed++;
                if (removed > 1) return false;
                if (i == 1 || nums[i] > nums[i - 2]) prev = nums[i];
            } 
            else {
                prev = nums[i];
            }
        }
        return true;
    }
};