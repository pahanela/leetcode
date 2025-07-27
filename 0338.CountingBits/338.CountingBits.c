/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize = n + 1;
    int *rtrn = (int *) malloc(*returnSize * sizeof(int));
    int count = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < sizeof(i) * CHAR_BIT; j++) {
            if ((i >> j) & 1UL)
                count++;
        }
        rtrn[i] = count;
        count = 0;
    }
    return rtrn;
}


// Brian Kernighan's algorithm
#ifdef FASTER_SOLUTION
int* countBits(int n, int* returnSize){
    *returnSize = n + 1;
    int *rtrn = (int *) malloc(*returnSize * sizeof(int));
    rtrn[0] = 0;
    for (int i = 1; i <= n; i++) {
        rtrn[i] = rtrn[i & i-1] + 1;
    }
    return rtrn;
}
#endif
