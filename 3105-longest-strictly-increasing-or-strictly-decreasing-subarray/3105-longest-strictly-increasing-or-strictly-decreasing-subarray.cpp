class Solution {
public:
    bool sorted(vector<int> &arr){
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i] <= arr[i-1]){
                return false;
            }
        }
        return true;
    }
    bool sortedRev(vector<int> &arr){
        int n = arr.size();
        for(int i=1; i<n; i++){
            if(arr[i] >= arr[i-1]){
                return false;
            }
        }
        return true;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int i=0; i<n; i++){
            vector<int> ans;
            for(int j=i; j<n; j++){
                ans.push_back(nums[j]);
                if(sorted(ans) || sortedRev(ans)){
                    int newLen = ans.size();
                    len = max(len, newLen);
                }
            }
        }
        return len;
    }
};