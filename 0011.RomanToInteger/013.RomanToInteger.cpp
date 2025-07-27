class Solution {
public:
    int romanToInt(string s) {
        int rtrn  = 0;
        std::map<char, int> mapOfSymbols = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            if (it != s.rbegin() && mapOfSymbols[*it] < mapOfSymbols[*prev(it)])
                rtrn -= mapOfSymbols[*it];
            else
                rtrn += mapOfSymbols[*it];
        }
        return rtrn;
    }
};

