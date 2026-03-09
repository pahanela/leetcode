class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();

        // initialize vector of flags
        vector<bool> present(n, false);

        // flag all the present elements
        for (int num : nums)
            present[num] = true;
        
        // find the missing one in the list of present
        for (int i = 0; i < n; ++i) {
            if (present[i] == false)
                return i;
        }

        // the upper bound of range
        return n;
    }
};

