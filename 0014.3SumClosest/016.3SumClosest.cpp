class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int rtrn = nums[0] + nums[1] + nums[nums.size() - 1];
        int curSum;
        int j;
        int k;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                curSum = nums[i] + nums[j] + nums[k];
                if (curSum < target) {
                    j++;
                }
                else if (curSum > target)
                    k--;
                else {
                    rtrn = curSum;
                    break;
                }
                if (abs(curSum - target) < abs(rtrn - target))
                    rtrn = curSum;
            }
        }
        return rtrn;
    }
};

