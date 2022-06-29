class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        int longest_start = 0;
        int longest_end = 0;
        for (int i = 0; i < s.size() * 2 - 2; i++) {
            if (i % 2) {
                start = (i - 1) / 2;
                end = (i + 1) / 2;
            }
            else {
                start = i / 2 - 1;
                end = i / 2 + 1;
            }
            while (start >= 0 && end < s.size() && s[start] == s[end]) {
                if (longest_end - longest_start < end - start) {
                    longest_start = start;
                    longest_end = end;
                }
                start--;
                end++;
            }
        }
        return s.substr(longest_start, longest_end - longest_start + 1);
    }
};

