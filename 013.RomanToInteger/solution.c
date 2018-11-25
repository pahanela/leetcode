int romanToInt(char* s) {
    int i = 0;
    char last = 0;
    int result = 0;
    while (i < strlen(s)){
        switch (s[i]){
            case 'M':
                if (last == 'C')
                    result += 800;
                else
                    result += 1000;
                break;
            case 'D':
                if (last == 'C')
                    result += 300;
                else
                    result += 500;
                break;
            case 'C':
                if (last == 'X')
                    result += 80;
                else
                    result += 100;
                break;
            case 'L':
                if (last == 'X')
                    result += 30;
                else
                    result += 50;
                break;
            case 'X':
                if (last == 'I')
                    result += 8;
                else
                    result += 10;
                break;
            case 'V':
                if (last == 'I')
                    result += 3;
                else
                    result += 5;
                break;
            case 'I':
                result += 1;
                break;
        }
        last = s[i];
        i++;
    }
    return result;
}

