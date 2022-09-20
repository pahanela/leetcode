class Solution {
public:
    bool isValid(string s) {
        bool rtrn = true;
        vector<char> brackets;
        for (char const &c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    brackets.push_back(c);
                    break;
                case ')':
                    if (brackets.size() > 0 && brackets.back() == '(') {
                        brackets.pop_back();
                        break;
                    }
                    else
                        return false;
                case '}':
                    if (brackets.size() > 0 && brackets.back() == '{') {
                        brackets.pop_back();
                        break;
                    }
                    else
                        return false;
                case ']':
                    if (brackets.size() > 0 && brackets.back() == '[') {
                        brackets.pop_back();
                        break;
                    }
                    else
                        return false;
            }
            
        }
        if (brackets.size() > 0)
            rtrn = false;
        return rtrn;
    }
};

