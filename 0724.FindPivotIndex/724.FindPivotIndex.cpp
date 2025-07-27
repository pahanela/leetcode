class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lSum = 0;
        int rSum = 0;
        int pivotIndex = -1;

        // calculate the sum of right Elements
        for (int i = 0; i < nums.size(); i++) {
            rSum += nums[i];
        }

        // evaluate the left edge scenario
        if (lSum == rSum - nums[0])
            return 0;

        // evaluate all other scenarios
        rSum -= nums[0];
        for (int i = 1; i < nums.size(); i++) {
            lSum += nums[i - 1];
            rSum -= nums[i];

            if (lSum == rSum) {
                pivotIndex = i;
                break;
            }
        }

        return pivotIndex;
    }
};

