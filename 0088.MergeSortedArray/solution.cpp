class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // padding start
        int left = m - 1;
        // padding end
        int right = m + n - 1;
        // currently processed element in num2
        int cur = n - 1;
        // process elements backwards
        while (cur >= 0) {
            // while there are elements in num1 present
            if (left >= 0 && nums1[left] >= nums2[cur]) {
                nums1[right] = nums1[left];
                left--;
            }
            else {
                nums1[right] = nums2[cur];
                cur--;
            }
            right--;
        }
    }
};

