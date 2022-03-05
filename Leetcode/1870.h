class Solution
{
public:
    bool arriveOnTime(vector<int>& dist, int speed, double hour)
    {
        double t = 0;
        for (int i = dist.size() - 2; i >= 0; --i)
        {
            t += ceil(1.0 * dist[i] / speed);
        }
        t += 1.0 * dist.back() / speed;
        return t <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        if ((double)(dist.size() - 1) >= hour)
            return -1;
        int l = 1, r = 1e7, mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (arriveOnTime(dist, mid, hour))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};