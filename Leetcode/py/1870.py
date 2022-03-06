from math import ceil

class Solution(object):
    def isArriveOnTime(self, dist, speed, hour):
        time = 0
        for d in dist[:-1]:
            time += ceil(d/speed)
        time += dist[-1] / speed
        return time <= hour

    def minSpeedOnTime(self, dist, hour):
        """
        :type dist: List[int]
        :type hour: float
        :rtype: int
        """
        if len(dist) - 1 >= hour:
            return -1
        l = 1
        r = 10**7
        while l < r:
            mid = int(l + (r - l) // 2)
            if self.isArriveOnTime(dist, mid, hour):
                r = mid
            else:
                l = mid + 1
        return r

dist = [1,3,2]
hour = 2.7
s = Solution()
print(s.minSpeedOnTime(dist, hour))
