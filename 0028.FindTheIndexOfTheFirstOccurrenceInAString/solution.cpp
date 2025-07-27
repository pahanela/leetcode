class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        // check if the haystack string has enough space for comparison
        while (i + j < haystack.length()) {
            // check if the currently pointed characters match and keep going
            if (haystack.at(i + j) == needle.at(j))
                j++;
            // otherwise, increment the start index in the outer string and reset the index for the match string
            else {
                i++;
                j = 0;
            };
            // check if we reached the end of the needle string, meaning the substring match
            if (j == needle.length())
                return i;
        };
        return -1;
    }
};

