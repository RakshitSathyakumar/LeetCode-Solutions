class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt=0;
        set<int> st;
        for(auto itr:nums) st.insert(itr);        
        for(int i=0;i<nums.size();i++){
            set<int> st1;
            for(int j=i;j<nums.size();j++){
                st1.insert(nums[j]);
                if(st1.size() == st.size()){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};