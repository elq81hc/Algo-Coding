from re import A


class Solution(object):
    def countServers(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        X, Y = list(map(sum, grid)), list(map(sum, zip(*grid)))
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if A[i][j] and X[i] + Y[j] > 2:
                    ans += X[i] + Y[j]
        return ans