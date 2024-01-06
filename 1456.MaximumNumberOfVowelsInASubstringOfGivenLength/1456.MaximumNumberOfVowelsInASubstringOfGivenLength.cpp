class Solution {
public:

    bool isVowel(char);

    int maxVowels(string s, int k) {
        int max = 0;
        int cur = 0;
        
        // calculate the number of vowels in the initial sliding window
        int i = 0;
        int j = i + k - 1;
        while (i < s.size() && i < k) {
            if (isVowel(s[i]))
                cur++;
            i++;
        }
        max = cur;

        // moving sliding window over the string
        i = 0;
        j = i + k - 1;
        while (j < s.size()) {
            if (isVowel(s[i++]))
                cur--;
            if (isVowel(s[++j]))
                cur++;
            if (cur > max)
                max = cur;
        }

        return max;
    }
};

bool Solution::isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
};

