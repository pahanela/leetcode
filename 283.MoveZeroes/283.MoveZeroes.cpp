class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = i + 1;
        
        while (j < nums.size()) {
            if (nums[i] != 0) {
                i++;
                j = i + 1;
            }
            else if (nums[i] == 0 && nums[j] == 0) {
                j++;
            }
            else if (nums[i] == 0 && nums[j] != 0) {
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
                j++;
            }
            else if (nums[i] != 0 && nums[j] != 0) {
                i++;
                j++;
            }
        }
    }
};

