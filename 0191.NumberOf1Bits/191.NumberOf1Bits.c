int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i = 0; i < sizeof(n) * CHAR_BIT; i++) {
        if (n & 1UL)
            count++;
        n >>= 1;
    }
    return count;
}

