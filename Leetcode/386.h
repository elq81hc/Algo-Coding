class Solution {
public:
/**
 * To calculate the next lexicographical number for any number X, there is only two scenarios to consider:
 * If we can add a trailing zero to it, then the next number is X * 10, because X * 10 is always the lexicographically smallest number bigger than X.
 * If X * 10 is bigger than the given number n, then the next smallest number can be generated by increasing X's least significant digit by 1. We have two sub-scenarios under this particular situation:
 * If X == n, then X + 1 is bigger than n, we need increase the second least significant digit in X, so we have if(cur == n) cur /= 10;
 * After we increased the number, we still need to take care another problem:
 * If the increased number has no trailing zeros, we can safely add it to result.
 * Otherwise we need to get rid of the trailing zeros, the reason is:
 * If the increased number has trailing zero/zeros, that mean we are actually increasing the digit right before the trailing zero
 * -> E.g. the next number to 1999 is 2, not 2000, because by adding 1 to the least significant digit, the first digit in 1999, which is the most significant digit, changed into 2.
*/
// O(N)
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        for (int i = 0, cur = 1; i < n; i++)
        {
            ret[i] = cur;
            if (cur * 10 <= n)
                cur *= 10;
            else {
                if (cur >= n)
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0)
                    cur /= 10;
            }
        }
        return ret;        
    }
// O(Nlog(N))
    //     vector<int> lexicalOrder(int n) {
    //     set<string> st;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         st.insert(to_string(i));
    //     }
    //     vector<int> a;
    //     for (auto& x : st) {
    //         a.push_back(stoi(x));
    //     }
    //     return a;
    // }
    
};