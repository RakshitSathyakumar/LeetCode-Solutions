class Solution {
public:
    int check(int st,int end,int chance,int sum1,int sum2,vector<int> nums){
        if(st > end || st>=nums.size() || end<0){
            return sum1>=sum2;
        }
        if(chance){
            return (check(st+1,end,!chance,nums[st]+sum1,sum2,nums)) || (check(st,end-1,!chance,sum1+nums[end],sum2,nums));
        }else{
            return (check(st+1,end,!chance,sum1,nums[st]+sum2,nums)) && (check(st,end-1,!chance,sum1,sum2+nums[end],nums));
        }
        
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        int res = check(0,nums.size()-1,1,0,0,nums);
        return res;
    }
};