class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool rtrn = false;
        int i = 0;
        int j = 0;

        for (int k = 1; k < nums.size(); k++) {
            // check the right condition first assuming the left condition was checked earlier
            if (nums[k] > nums[j] && j > 0) {
                rtrn = true;
                break;
            }
            // check if there is a new minimum
            if (nums[k] < nums[i]) {
                i = k;
                continue;
            }
            // check the left condition
            if (nums[k] > nums[i])
                j = k;
        };
        return rtrn;
    }
};

