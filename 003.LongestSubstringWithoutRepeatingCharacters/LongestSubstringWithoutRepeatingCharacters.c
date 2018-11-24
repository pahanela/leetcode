// brute force
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

// running window solution, causes time exceeded limit error
int lengthOfLongestSubstring(char* s) {
    int pos[128] = {0};
    int beg = 0;
    int end = 0;
    int max = 0;
    if (strlen(s) > 0){
        max = 1;
        while (end < strlen(s)){
            if (pos[s[end]] != 0){
                if (pos[s[end]] - 1 >= beg)
                    beg = pos[s[end]];
            }
            pos[s[end]] = end + 1;
            end++;
            if (end - beg > max)
                max = end - beg;
        }
    }
    return max;
}
