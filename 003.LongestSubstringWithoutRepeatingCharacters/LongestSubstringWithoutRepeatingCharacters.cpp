class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int start = 0;
        int maxLen = 0;
        int counter = 0;
        unordered_map <char, int> chars;
        for(char& c : s) {
            if (chars.count(c)) {
                if (counter > maxLen) {
                    maxLen = counter;
                }
                if (chars[c] > start)
                    start = chars[c];
                counter = i - start;
                chars[c] = i;
            }
            else {
                chars.insert({c, i});
                counter++;
            }
            i++;
        }
        if (counter > maxLen)
            maxLen = counter;
        return maxLen;
    }
};

