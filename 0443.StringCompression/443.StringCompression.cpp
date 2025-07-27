class Solution {
public:
    int compress(vector<char>& chars) {
        int charsLength = chars.size();
        if (charsLength == 0)
            return 0;
        if (charsLength == 1)
            return 1;
        int i = 0;
        int set = 1;
        vector<int> digits;
        for (int j = 1; j < charsLength; j++) {
            if (chars[j] != chars[i]) {
                if (set > 1) {
                    while (set > 9) {
                        digits.insert(digits.begin(), set % 10);
                        set = set / 10;
                    }
                    digits.insert(digits.begin(), set);
                    for (int digit : digits)
                        chars[++i] = '0' + digit;
                    digits.clear();
                    set = 1;
                }
                chars[++i] = chars[j];
            }
            else
                set++;
        }
        if (set > 1) {
            while (set > 9) {
                digits.insert(digits.begin(), set % 10);
                set = set / 10;
            }
            digits.insert(digits.begin(), set);
            for (int digit : digits)
                chars[++i] = '0' + digit;
        }
        i++;
            
        return i;
    }
};

