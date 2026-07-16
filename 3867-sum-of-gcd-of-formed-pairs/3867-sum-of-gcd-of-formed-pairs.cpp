class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        vector<int> res(n, -1);
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            int gcdNum = __gcd(maxi, nums[i]);
            res[i] = gcdNum;
        }
        sort(res.begin(), res.end());
        int start = 0;
        int end = n-1;
        long long sum = 0;
        while(start < end){
            int takeGcd = __gcd(res[start], res[end]);
            sum += takeGcd;
            start++;
            end--;
        }
        return sum;
    }
};