class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n) {
            if (!((n ^ (n >> 1)) & 0x1))
                return false;
            n >>= 1;
        }
        return true;
    }
};

