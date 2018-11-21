/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *pair = malloc(2*sizeof(int));
    int found = 0;
    for (int i = 0; i < numsSize; i++){
        for (int j = i + 1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                pair[0] = i;
                pair[1] = j;
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }
    return pair;
}