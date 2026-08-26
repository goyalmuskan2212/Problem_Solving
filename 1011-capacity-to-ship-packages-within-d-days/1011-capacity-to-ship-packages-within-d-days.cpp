class Solution {
public:
    int check(vector<int>& weights, int weigh){
        int n = weights.size();
        int days = 1;
        int sum = 0;
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            if(sum > weigh){
                days++;
                sum = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            int numDays = check(weights, mid);
            if(numDays <= days){
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