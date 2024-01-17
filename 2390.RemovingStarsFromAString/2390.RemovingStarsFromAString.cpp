class Solution {
public:
    string removeStars(string s) {

        // process the input string with help of stack
        std::stack<char> rtrnStack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*')
                rtrnStack.push(s[i]);
            else
                rtrnStack.pop();
        }

        // move characters from the stack to the string
        std::string rtrnString;
        while (rtrnStack.size()) {
            rtrnString.push_back(rtrnStack.top());
            rtrnStack.pop();
        }

        // reverse the string as it contains the characters in the wrong order
        std::reverse(rtrnString.begin(), rtrnString.end());

        return rtrnString;
    }
};

