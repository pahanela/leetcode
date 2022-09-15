class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> rtrn;
        if (digits.length() == 0)
            return rtrn;
        rtrn.push_back("");
        std::vector<string> keypad = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        for (int i = 0; i < digits.length(); i++) {
            int key = digits[i] - '0';
            while (rtrn.front().length() == i) {
                string permutation = rtrn.front();
                rtrn.erase(rtrn.begin());
                for (char const &c : keypad[key])
                    rtrn.push_back(permutation + c);
            }
        }
        return rtrn;
    }
};

