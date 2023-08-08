class Solution {
public:
    int bsear(vector<int>& nums,int st,int ed,int target)
    {
        // int st=0,ed=nums.size()-1,mid;
        while(st<=ed)
        {
            int mid=st+(ed-st)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                st=mid+1;
            else
                ed=mid-1;
        }
        return -1;
    }
    
    int minIndex(vector<int>& nums)
    {
    int n=nums.size();
        int ans;
        int st=0,ed=nums.size()-1,mid;
        if(nums[ed]>=nums[st])
        {
            return 0;
        }
        else{
            while(st<=ed)
            {
            mid=(ed+st)/2;
            int prevs,nxt;
            nxt=(mid+1)%n;
            prevs=(mid+n-1)%n;
            if(nums[mid]<=nums[prevs] && nums[mid]<=nums[nxt])
                return mid;
            else if(nums[mid]>nums[ed])
                st=mid+1;
            else
                ed=mid;
            }
        return -1;
        }
    }
    
    int helper(int x,int y)
    {
        
        if(x==-1 && y!=-1)
            return y;
        else if(x!=-1 && y==-1)
            return x;
        else
            return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int l=minIndex(nums);
        if(nums[l] == target)
        {
            return l;
        }
        int x1=bsear(nums,0,l-1,target);
        int x2=bsear(nums,l+1,nums.size()-1,target);
        return helper(x1,x2);
        // return l;
        // int res=helper(x1,x2);
        // if(res==-1)
        //     return -1;
        // return res;
    }
};