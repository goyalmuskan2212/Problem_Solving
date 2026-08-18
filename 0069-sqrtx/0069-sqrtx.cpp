class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int ans = x;
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long sqt = mid*mid;
            if(sqt <= (long long)x){
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