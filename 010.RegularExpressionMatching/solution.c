bool isMatch(char* s, char* p) {
    bool result;
    if (s[0] == '\0' && p[0] == '\0')
        result = true;
    else if (s[0] != '\0' && p[0] == '\0')
        result = false;
    else if (s[0] == '\0' && p[0] != '\0'){
        if (p[1] == '*')
            result = isMatch(s, &p[2]);
        else
            result = false;
    }
    else if (s[0] != '\0' && p[0] != '\0'){
        if (p[1] == '\0'){
            if (s[0] == p[0] || p[0] == '.')
                result = isMatch(&s[1], &p[1]);
            else
                result = false;
        }
        else if (p[1] == '*'){
            if (s[0] == p[0] || p[0] == '.')
                result = isMatch(&s[0], &p[2]) || isMatch(&s[1], &p[2]) || isMatch(&s[1], &p[0]);
            else
                result = isMatch(&s[0], &p[2]);
        }
        else{
            if (s[0] == p[0] || p[0] == '.')
                result = isMatch(&s[1], &p[1]);
            else
                result = false;
        }
    }
    return result;
}
