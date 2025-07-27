class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i1 = 0;
        int i2 = 0;
        double prev = 0;
        double next = 0;
        if (len1 == 0) {
            i2 = len2 / 2;
            if (i2 > 0) {
                i2--;
                prev = nums2[i2];
            }
            if (i2 + 1 < len2)
                next = nums2[i2 + 1];
            else
                next = nums2[i2];
        }
        if (len2 == 0) {
            i1 = len1 / 2;
            if (i1 > 0) {
                i1--;
                prev = nums1[i1];
            }
            if (i1 + 1 < len1)
                next = nums1[i1 + 1];
            else
                next = nums1[i1];
        }
        if (len1 > 0 && len2 > 0) {
            while (i1 + i2 < (len1 + len2) / 2) {
                if (i1 == len1) {
                    prev = next;
                    i2++;
                    next = nums2[i2];
                }
                else if (i2 == len2) {
                    prev = next;
                    i1++;
                    next = nums1[i1];
                }
                else {
                    if (nums1[i1] <= nums2[i2]) {
                        prev = nums1[i1];
                        i1++;
                        if (i1 == len1)
                            next = nums2[i2];
                        else {
                            if (nums1[i1] <= nums2[i2])
                                next = nums1[i1];
                            else
                                next = nums2[i2];
                        }
                    }
                    else {
                        prev = nums2[i2];
                        i2++;
                        if (i2 == len2)
                            next = nums1[i1];
                        else {
                            if (nums1[i1] <= nums2[i2])
                                next = nums1[i1];
                            else
                                next = nums2[i2];
                        }
                    }
                }
            }
        }
        if ((len1 + len2) % 2)  // odd
            median = next;
        else
            median = (prev + next) / 2.;
        return median;
    }
};

