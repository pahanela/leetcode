class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (a || b || c) {
            if ((((a | b) & 0x1)) != (c & 0x1)) {
                if (a & 0x1 && b & 0x1)
                    flips++; // double flips for "1 OR 1 != 0" scenario
                flips++;
            }
            a >>= 0x1;
            b >>= 0x1;
            c >>= 0x1;
        }
        return flips;
    }
};

