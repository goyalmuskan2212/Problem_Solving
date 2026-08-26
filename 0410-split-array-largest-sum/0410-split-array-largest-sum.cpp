class Solution {
public:
    bool possible(vector<int> &nums, int maxi, int k){
        int n = nums.size();
        int sum = 0;
        int arrCnt = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum > maxi){
                arrCnt++;
                sum = nums[i];
            }
            if(arrCnt > k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            bool check = possible(nums, mid, k);
            if(check){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};