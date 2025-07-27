class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int cur = 0;
        int prev2 = 1;
        int prev1 = 2;
        for (int i = 2; i < n; ++i) {
            cur = prev2 + prev1;
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};

