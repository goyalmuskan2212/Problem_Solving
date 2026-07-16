class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            else if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
        }
        vector<int> ans;
        int i = 0;
        while(i<min(pos.size(), neg.size())){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }
        while(i < pos.size()){
            ans.push_back(pos[i]);
            i++;
        }

        while(i < neg.size()){
            ans.push_back(neg[i]);
            i++;
        }
        return ans;
    }
};