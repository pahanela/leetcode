class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int number = 0;
        int rtrn = 0;
        // read and ignore any leading character
        while (s[i] == ' ')
            i++;
        // check if - or +
        switch (s[i]) {
            case '-':
                sign = -1;
                i++;
                break;
            case '+':
                sign = 1;
                i++;
                break;
            case '0' ... '9':
                break;
            default:
                break;
        }
        // read digits
        while(isdigit(s[i])) {
            if (sign > 0 && number > INT_MAX / 10) {
                rtrn = INT_MAX;
                break;
            }
            else if (sign < 0 && sign * number < INT_MIN / 10) {
                rtrn = INT_MIN;
                break;
            }
            number *= 10;
            if (sign > 0 && number > INT_MAX - (s[i] - '0')) {
                rtrn = INT_MAX;
                break;
            }
            else if (sign < 0 && sign * number <= INT_MIN + (s[i] - '0')) {
                rtrn = INT_MIN;
                break;
            }
            
            number += s[i] - '0';
            i++;
        }
        if (sign > 0 && rtrn != INT_MAX)
            rtrn = number;
        else if (sign < 0 && rtrn != INT_MIN)
            rtrn = sign * number;
        return rtrn;
    }
};

