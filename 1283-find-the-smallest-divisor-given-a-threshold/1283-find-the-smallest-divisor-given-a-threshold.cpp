class Solution {
public:
    int possible(vector<int> &nums, int divisor){
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += ceil((double)nums[i]/divisor);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            int check = possible(nums, mid);
            if(check <= threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};