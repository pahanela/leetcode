class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int counter = 0;
        
        // sort the vector
        sort (nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        
        // find the tail
        while (i < j && nums[j] > k)
            j--;
        
        // find the head
        while (i < j) {
            if (nums[i] + nums[j] == k) {
                counter++;
                i++;
                j--;
            }
            else if (nums[i] + nums[j] < k)
                i++;
            else if (nums[i] + nums[j] > k)
                j--;
        }
        
        return counter;
    }
};

