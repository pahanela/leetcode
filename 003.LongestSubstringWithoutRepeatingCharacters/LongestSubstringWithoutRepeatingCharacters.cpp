class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int counter = 0;
        unordered_set <char> chars;
        for(char& c : s) {
            if (chars.count(c)) {
                if (counter > maxLen) {
                    maxLen = counter;
                    counter = 0;
                }
            }
            else
                counter++;
            
        }
        return maxLen;
    }
};


