class Solution {
public:
    bool good(int mid,int p,vector<int> nums){
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] - nums[i] <= mid){
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l=0,r=1e9;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(good(mid,p,nums)){
                r=mid;
            }else{
                l=mid;
            }
        }
        if(good(l,p,nums)) return l;
        return r;
    }
};