uint32_t reverseBits(uint32_t n) {
    uint32_t rtrn = 0;
    for (uint8_t i = 0; i < sizeof(n) * CHAR_BIT; i++) {
        rtrn <<= 1;
        if (n & 1UL)
            rtrn |= 1UL;
        n >>= 1;
    }
    return rtrn;
}

