class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> mini = {INT_MAX, -1};
        pair<int, int> maxi = {INT_MIN, -1};
        for(int i=0; i<n; i++){
            if(nums[i] > maxi.first){
                maxi = {nums[i], i};
            }
            if(nums[i] < mini.first){
                mini = {nums[i], i};
            }
        }
        int dismini1 = (mini.second + 1);
        int dismini2 = (n - mini.second);
        int dismaxi1 = (maxi.second + 1);
        int dismaxi2 = (n - maxi.second);
        
        int option1 = max(dismini1, dismaxi1);

        int option2 = max(dismini2, dismaxi2);

        int option3 = min(dismini1 + dismaxi2, dismaxi1 + dismini2);

        return min({option1, option2, option3});
    }
};