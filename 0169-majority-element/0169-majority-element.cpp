class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el = nums[0];
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == el){
                cnt++;
            }
            else cnt--;
            if(cnt == 0){
                el = nums[i];
                cnt++;
            }
        }
        cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == el){
                cnt++;
            }
        }
        if(cnt > (n/2)) return el;
        return -1;
    }
};