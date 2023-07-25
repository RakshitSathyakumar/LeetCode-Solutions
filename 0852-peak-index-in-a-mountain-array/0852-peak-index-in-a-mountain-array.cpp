class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=0,ed=arr.size()-1;
        int mid;
        while(st<ed)
        {
            mid=st+(ed-st)/2;
            if(arr[mid]<arr[mid+1])
                st=mid+1;
            else
                ed=mid;
        }
        return ed;
    }
};