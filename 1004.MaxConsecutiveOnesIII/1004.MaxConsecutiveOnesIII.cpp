class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max = 0;
        int ones = 0;
        int zeroes = 0;
        int i = 0;
        int j = 0;

        while (j < nums.size()) {
            
            // identify the currently pointed element
            if (nums[j] == 1)
                ones++;
            else
                zeroes++;
            
            // update max if necessary
            if (zeroes <= k && ones + zeroes > max)
                max = ones + zeroes;
            else if (zeroes > k && ones + k > max)
                max = ones + k;
            
            // increment left pointer if necessary
            if (zeroes > k) {
                if (nums[i] == 1)
                    ones--;
                else
                    zeroes--;
                i++;
            }

            // increment right pointer
            j++;
        };

        return max;
    }
};

