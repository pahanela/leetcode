class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        while (s.at(end) == ' ')
            end--;
        int i = end;
        while (i >= 0 && s.at(i) != ' ')
            --i;
        return end - i;
    }
};

