class Solution {
public:
    string reverseWords(string s) {
        string reversed = "";
        int i = s.length();
        int iws = i;
        int iwe = i;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (iws < iwe) {
                    reversed.append(s.substr(iws, iwe - iws));
                    reversed.append(" ");
                }
                iws = i;
                iwe = i;
            }
            else {
                iws = i;
            }
        };
        if (iws < iwe)
            reversed.append(s.substr(iws, iwe - iws));
        else
            reversed.pop_back();
        return reversed;
    };
};
