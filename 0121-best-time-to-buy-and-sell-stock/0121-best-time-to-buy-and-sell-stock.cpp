class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int cost = 0;
        for(int i=0; i<n; i++){
            int profit = prices[i] - mini;
            cost = max(cost, profit);
            mini = min(mini, prices[i]);
        }
        return cost;
    }
};