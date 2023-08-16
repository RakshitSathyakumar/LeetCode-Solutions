class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i=0,j=0;
        if(nums.size() == 1){
            return {nums[0]};
        }
        int res =-1e9;
        multiset<int> mst;
        while(j < nums.size()){
            if(j - i + 1 < k){
                mst.insert(nums[j]);
                j++;
            }else if(j-i+1 == k){
                mst.insert(nums[j]);
                ans.push_back(*mst.rbegin());
                mst.erase(mst.find(nums[i]));
                i++;j++;
            }
        }
        return ans;
    }
};