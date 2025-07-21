class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0) {
            digits[i]++;
            if (digits[i] >= 10)
                digits[i] %= 10;
            else
                break;
            i--;
        }
        if (i < 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

