class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 1;
        int high = *max_element(arr.begin(), arr.end()) + k;
        int ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            int num = lower_bound(arr.begin() ,arr.end(), mid) - arr.begin();
            int numMissPlace = mid - num;
            if(numMissPlace <= k){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};