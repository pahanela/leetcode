
char * longestCommonPrefix(char ** strs, int strsSize){
    char * rtrn = "";
    int len = 0;
    char ch = '\0';
    int match = true;
    if (strsSize < 1)
    {
        match = false;
    }
    while (match)
    {
        ch = strs[0][len];
        for (int i = 0; i < strsSize; i++)
        {
            if (('\0' == ch) || ('\0' == strs[i][len]) || (strs[i][len] != ch))
            {
                strs[0][len] = '\0';
                match = false;
                break;
            }
        }
        len++;
    }
    if (len > 0)
    {
        rtrn = (char *) malloc(sizeof(char) * len);
        strcpy(rtrn, strs[0]);
    }
    return rtrn;
}

