class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> nums;
        for(int i=0;i<=n;i++){
            int cnt=0;
            int res=i;
            while(res>0){
                res=res&(res-1);
                cnt++;
            }
            nums.push_back(cnt);
        }
        return nums;
    }
};