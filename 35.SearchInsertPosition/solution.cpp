class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // when target number is less than the very first element, return the very first index which is 0
        if (target < nums[0])
            return 0;
        for (int i = 0; i < nums.size(); ++i) {
            // if match is found, return its index
            if (nums[i] == target)
                return i;
            // if the end is reached or the next element is larget, return the next index
            if (i + 1 == nums.size() || (nums[i] < target && target < nums[i + 1]))
                return i + 1;
        }
        return -1;
    }
};

