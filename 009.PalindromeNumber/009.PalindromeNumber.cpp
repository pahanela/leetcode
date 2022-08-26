class Solution {
public:
    bool isPalindrome(int x) {
        long rev = 0;
        int reminder = x;
        int rtrn = false;
        while (reminder > 0) {
            rev = rev * 10 + reminder % 10;
            reminder /= 10;
        }
        if (rev == x)
            rtrn = true;
        return rtrn;
    }
};

