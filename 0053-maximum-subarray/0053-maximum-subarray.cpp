class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi = INT_MIN + 9;
        int sum=0;
        int ansSt = -1 , ansEnd = -1;
        for(int i=0;i<n;i++){
            if(sum == 0) ansSt = i;
            sum+=nums[i];
            if(sum > maxi){
                maxi=sum;
                ansEnd = i;
            }
            if(sum < 0) sum = 0;
        }
        cout<<ansSt<<' '<<ansEnd<<endl;
        return maxi;
    }
};