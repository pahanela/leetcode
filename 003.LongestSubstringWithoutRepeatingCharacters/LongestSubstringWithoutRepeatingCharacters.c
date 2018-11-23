int lengthOfLongestSubstring(char* s) {
    char pos[128] = {0};
    int i = 0;
    int len = 0;
    int max = 0;
    while (i < strlen(s)){
        if (pos[s[i]]){
            i = pos[s[i]];
            len = 0;
            memset(pos, 0, sizeof(pos));
        }
        else{
            pos[s[i]] = i + 1;
            len++;
            if (len > max)
                max = len;
            i++;
        }
    }
    return max;
}
