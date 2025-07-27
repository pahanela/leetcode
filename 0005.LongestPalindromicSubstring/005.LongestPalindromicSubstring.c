char* longestPalindrome(char* s) {
    int maxLen = 1;
    int maxBegin = 0;
    int beg = 0;
    int end = 0;
    for (int i = 0; s[i] != '\0' && s[i+1] != '\0' && i < 1000; i++){
        // odd case
        beg = i;
        end = i;
        while(beg - 1 >= 0 && end + 1 < 1000 && s[beg - 1] == s[end + 1]){
            beg--;
            end++;
        }
        if (maxLen < end - beg + 1){
            maxLen = end - beg + 1;
            maxBegin = beg;
        }
        // even case
        if (s[i] == s[i + 1]){
            beg = i;
            end = i + 1;
            while(beg - 1 >= 0 && end + 1 < 1000 && s[beg - 1] == s[end + 1]){
                beg--;
                end++;
            }
            if (maxLen < end - beg + 1){
                maxLen = end - beg + 1;
                maxBegin = beg;
            }
        }
    }
    char *longestPal = (char *) malloc(sizeof(char) * (maxLen + 1));
    for (int j = 0; j < maxLen; j++)
        longestPal[j] = s[j + maxBegin];
    longestPal[maxLen] = '\0';
    return longestPal;
}

