bool isPowerOfFour(int n) {
    // 1. n must be positive
    // 2. n must be a power of two (only one bit set)
    // 3. The single set bit must be at an even position.
    //    0x55555555 is a bitmask where only even-indexed bits are set (0, 2, 4, ...)
    return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0x55555555) != 0);
}

