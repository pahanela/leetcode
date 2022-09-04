class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string rtrn = "";
        int min_len = strs[0].length();
        bool match = true;
        for (auto str : strs) {
            if (str.length() < min_len)
                min_len = str.length();
        }
        for (int i = 0; match && i < min_len; i++) {
            for (auto str: strs) {
                if (str[i] != strs[0][i]) {
                    match = false;
                    break;
                }
            }
            if (match)
                rtrn.push_back(strs[0][i]);
        }
        return rtrn;
    }
};

