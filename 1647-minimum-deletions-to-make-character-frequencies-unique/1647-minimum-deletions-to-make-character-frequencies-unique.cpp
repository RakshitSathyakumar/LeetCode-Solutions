class Solution {
public:
    int minDeletions(string s) {
        vector<int> vch(26,0);
        for(auto itr:s){
            vch[itr-'a']++;
        }
        vector<int> nums;
        for(auto itr:vch){
            if(itr) nums.push_back(itr);
        }
        sort(nums.rbegin(),nums.rend());
        int z=0;
        for(auto itr:nums) cout<<itr<<" ";
        map<int,int> mp;
        mp[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            if(mp.find(nums[i]) == mp.end()){ mp[nums[i]]++;continue;}
            while(mp.find(nums[i]) != mp.end() && nums[i]>=0) {
                nums[i]--,z++;
                if(!nums[i]) mp.erase(nums[i]);
            }
            mp[nums[i]]++; 
        }
        return z;
    }
};