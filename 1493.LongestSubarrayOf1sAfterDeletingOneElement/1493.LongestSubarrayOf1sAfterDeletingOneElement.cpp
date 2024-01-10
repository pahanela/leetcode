class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max = 0;
        int ones = 0;
        int zeroes = 0;
        int i = 0;
        int j = 0;

        while (j < nums.size()) {
            // increment the right pointer
            if (nums[j++] == 1) {
                ones++;
            }
            else
                zeroes++;

            // increment the left pointer
            while (zeroes > 1 && i < j) {
                if (nums[i++] == 1)
                    ones--;
                else
                    zeroes--;
            }

            // update max if necessary
            if (ones + zeroes > max)
                max = ones;

            // if there are no zeroes we must delete one element anyway
            if (zeroes == 0)
                max--;
        }

        return max;
    }
};

