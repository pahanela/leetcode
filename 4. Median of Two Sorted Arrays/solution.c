double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mid1 = nums1[nums1Size / 2];
    int mid2 = nums2[nums2Size / 2];
    double mid = (mid1 + mid2) / 2;
    return mid;
}
