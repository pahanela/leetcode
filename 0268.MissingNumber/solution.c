int missingNumber(int* nums, int numsSize) {
    
    int missing = 0;

    for (int i = 0; i < numsSize; ++i) {
        missing ^= nums[i];
        missing ^= i + 1;
    }

    return missing;
}

