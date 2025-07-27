class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max = 0.0;
        double cur = 0.0;
        
        // calculate the initial value of the sliding window
        for (int i = 0; i < k; i++)
            cur += (double)nums[i]/k;
        max = cur;
            
        int left = 0;
        int right = k;
        while (right < nums.size()) {
            cur = cur + (double)nums[right++]/k - (double)nums[left++]/k;
            if (cur > max)
                max = cur;
        }
        
        return max;
    }
};

