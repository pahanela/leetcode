class Solution {
public:
    int reverse(int x) {
        int rtrn = 0;
        while (x != 0) {
            if (abs(rtrn) <= 0x7FFFFFFF / 10) {
                rtrn = rtrn * 10 + x % 10;
                x /= 10;
            }
            else {
                rtrn = 0;
                break;
            }
        }
        return rtrn;
    }
};

