class Solution
{
public:
    double timeTaken(vector<int> &dist, int speed)
    {
        double t = 1.0 * dist.back() / speed;
        for (int i = dist.size() - 2; i >= 0; --i)
        {
            t += ceil(dist[i] / speed);
        }
        return t;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        if (dist.size() - 1 > hour)
            return -1;
        int l = 0, r = 1000000000;
        int ans = 0;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
        }
        return ans > 0 ? ans : -1;
    }
};