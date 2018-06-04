double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums[nums1Size + nums2Size];
    int i = 0;
    int j = 0;
    int k = 0;
    double mid;
    while(k < nums1Size + nums2Size){
        if (i < nums1Size && j < nums2Size){
            if (nums1[i] <= nums2[j]){
                nums[k] = nums1[i];
                i++;
            }
            else{
                nums[k] = nums2[j];
                j++;
            }
            k++;
        }
        else if (i < nums1Size && j == nums2Size){
            while(i < nums1Size){
                nums[k] = nums1[i];
                i++;
                k++;
            } 
        }
        else if (i == nums1Size && j < nums2Size){
            while(j < nums2Size){
                nums[k] = nums2[j];
                j++;
                k++;
            }
        }
    }
    if (k > 1){
        if (k % 2)
            mid = nums[k / 2];
        else
            mid = (double) (nums[k / 2 - 1] + nums[k / 2]) / 2;
    }
    else
        mid = nums[0];
    return mid;
}
