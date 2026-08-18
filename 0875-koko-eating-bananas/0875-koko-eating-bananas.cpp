class Solution {
public:
    int solve(vector<int>& piles, int num){
        int n = piles.size();
        long long res = 0;
        for(int i=0; i<n; i++){
            res += ceil((double)(piles[i]) / (double)(num));
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(h == 1000000000) return n;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            int check = solve(piles, mid);
            if(check <= h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};