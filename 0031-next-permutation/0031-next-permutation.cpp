class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int res=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                res=i;
                break;
            }
        }
        // cout<<res;
        if(res == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=nums.size()-1;i>res;i--){
            if(nums[i] > nums[res]){
                swap(nums[i],nums[res]);
                break;
            }
        }
        reverse(nums.begin()+res+1,nums.end());
    }
};