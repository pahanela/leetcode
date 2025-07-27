class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        
        // traverse the input array forward to calculate prefix
        vector<int> prefix(nums.size());
        prefix[0] = 1; // the value for the left most element
        prefix[1] = nums[0]; // the value for the second left most element
        for (int i = 2; i < nums.size(); i++)
            prefix[i] = nums[i - 1] * prefix[i - 1];
        
        // traverse the input array backward to calculate sufix
        vector<int> sufix(nums.size());
        sufix[nums.size() - 1] = 1;
        sufix[nums.size() - 2] = nums[nums.size() - 1];
        for (int i = nums.size() - 3; i >= 0; i--)
            sufix[i] = nums[i + 1] * sufix[i + 1];
        
        // calculate the final result
        for (int i = 0; i < nums.size(); i++)
            result[i] = prefix[i] * sufix[i];
        
        return result;
    }
};

