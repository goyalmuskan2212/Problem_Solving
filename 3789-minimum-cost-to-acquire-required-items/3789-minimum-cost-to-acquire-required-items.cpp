class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = (min(need1, need2));
        ans = ans * (min(costBoth, cost1+cost2));
        long long rem1 = need1 - min(need1, need2);
        rem1 = rem1 * min(costBoth, cost1);
        long long rem2 = need2 - min(need1, need2);
        rem2 = rem2 * min(costBoth, cost2);
        ans += rem1;
        ans += rem2;
        return ans;
    }
};