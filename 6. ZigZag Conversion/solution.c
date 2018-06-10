char* convert(char* s, int numRows) {
    int len = 0;
    int i = 0;
    while (s[i++] != '\0')
        len++;
    char* sOut = malloc(sizeof(char) * len);
    i = 0;
    while(i < len){
        if (!(i % (numRows * 2 - 2)))
            sOut[i] = s[i];
        i++;
    }
    return sOut;
}

