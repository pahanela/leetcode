int myAtoi(char* str) {
    signed long min = -pow(2, 31);
    signed long max = pow(2, 31) - 1;
    signed long value = 0;
    signed char sign = 1;
    int i = 0;
    // chomp leading space characters
    while (str[i] == ' ')
        i++;
    // determine the sign 
    if (str[i] == '-'){
        sign = -1;
        i++;
    }
    else if (str[i] == '+'){
        sign = 1;
        i++;
    }
    // chomp leading zeroes if any
    while (str[i] == '0')
        i++;
    // check that next character is a digit
    if (str[i] >= 0x30 && str[i] <= 0x39){
        value = sign * (str[i] - 0x30);
        i++;
    }
    else
        return 0;
    // keep rolling
    while (str[i] >= 0x30 && str[i] <= 0x39){
        if (value > 0 && value > max / 10)
            return max;
        else if (value < 0 && value < min / 10)
            return min;
        else{
            value *= 10;
            if (value >= 0){
                if (value < max - (str[i] - 0x30))
                    value += str[i] - 0x30;
                else
                    return max;
            }
            else if (value < 0){
                if (value > min + (str[i] - 0x30))
                    value -= str[i] - 0x30;
                else
                    return min;
            }
        }
        i++;
    }
    return value;
}

