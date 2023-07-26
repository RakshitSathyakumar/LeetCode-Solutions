class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        l=1
        r=1e9
        min_speed = -1
        while(r >= l):
            mid = (r-l)//2 + l
            res = sum([ceil(d / mid) for d in dist[:-1]], 0) + dist[-1] / mid <= hour
            if(res):
                min_speed = mid
                r=mid-1
            else:
                l=mid+1
        
        return int(min_speed);