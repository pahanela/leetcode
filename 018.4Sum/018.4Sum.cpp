class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rtrn;
        if (nums.size() < 4) {
            return rtrn;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    long int sum = 0;
                    sum += nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum > INT_MAX || sum < INT_MIN)
                        break;
                    if (sum == target) {
                        vector<int> combination = {nums[i], nums[j], nums[k], nums[l]};
                        if (find(rtrn.begin(), rtrn.end(), combination) == rtrn.end())
                            rtrn.push_back(combination);
                        k++;
                        l--;
                    }
                    if (sum < target) {
                        while (k < l && nums[k] == nums[k + 1])
                            k++;
                        k++;
                    }
                    if (sum > target) {
                        while (k < l && nums[l - 1] == nums[l])
                            l--;
                        l--;
                    }
                }
            }
        }
        return rtrn;
    }
};

