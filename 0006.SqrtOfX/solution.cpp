class Solution {
public:
    int mySqrt(int x) {
        int max = 46340;  // square root of max 32-bit signed integer type.
        int rtrn = 0;
        int lim = 0x1 << 15;
        int cur = 0x1;
        while (lim && rtrn * rtrn < x) {
            while (cur <= lim && rtrn + cur <= max && ((rtrn + cur) * (rtrn + cur) < x))
                cur <<= 1;
            if (rtrn + cur > max || ((rtrn + cur) * (rtrn + cur) > x))
                cur >>= 1;
            rtrn += cur;
            lim >>= 1;
            cur = 0x1;
        }
        return rtrn;
    }
};

