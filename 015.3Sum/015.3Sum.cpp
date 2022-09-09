class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> rtrn;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                break;
            int j = i + 1;
            int k = n - 1;
            while (j < n && j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    rtrn.push_back({nums[i],nums[j],nums[k]});
                    while(j! = n-1 && nums[j] == nums[j+1])
                        j++;
                    while(k! = 0 && nums[k] == nums[k-1])
                        k--;
                    j++;
                    k--;
                }
                else if (-nums[i] < (nums[j] + nums[k])) {
                    while (k != 0 && nums[k] == nums[k - 1])
                        k--;
                    k--;
                }
                else {
                    while (j != n - 1 && nums[j] == nums[j + 1])
                        j++;
                    j++;
                }
            }
            while (i != n - 1 && nums[i] == nums[i + 1])
                i++;
        }
        return rtrn;
    }
};

