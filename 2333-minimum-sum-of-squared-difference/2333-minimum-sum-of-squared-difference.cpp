
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        long long total = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxi = max(maxi, diff[i]);
        }

        long long k = (long long)k1 + k2;
        if (k >= total) return 0;

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long remaining = k;
        long long ans = 0;

        for (int d : diff) {
            if (d > low) {
                remaining -= d - low;
                d = low;
            }
            ans += 1LL * d * d;
        }

        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= low && low > 0) {
                ans -= 2LL * low - 1;
                remaining--;
            }
        }

        return ans;
    }
};
