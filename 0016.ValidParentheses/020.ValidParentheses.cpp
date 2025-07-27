class Solution {
public:
    bool isValid(string s) {
        bool rtrn = true;
        vector<char> brackets;
        for (int i = 0; i < s.size() && rtrn == true; ++i) {
            switch (s[i]) {
                case '(':
                case '{':
                case '[':
                    brackets.push_back(s[i]);
                    break;
                case ')':
                    if (brackets.size() > 0 && brackets.back() == '(') {
                        brackets.pop_back();
                        break;
                    }
                    else
                        rtrn = false;
                case '}':
                    if (brackets.size() > 0 && brackets.back() == '{') {
                        brackets.pop_back();
                        break;
                    }
                    else rtrn = false;
                case ']':
                    if (brackets.size() > 0 && brackets.back() == '[') {
                        brackets.pop_back();
                        break;
                    }
                    else rtrn = false;
                default:
                    break;
            }
            
        }
        if (brackets.size() > 0)
            rtrn = false;
        return rtrn;
    }
};

