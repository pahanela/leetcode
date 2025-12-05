class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int rtrn = 0;

        for (int num : nums) {
            if (!(num % 2))
                rtrn |= num;
        }

        return rtrn;
    }
};

