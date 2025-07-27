class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        std::map<int, char> values = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };
        for (auto iter = values.rbegin(); iter != values.rend(); ++iter) {
            switch (num / iter->first) {
                case 0:
                    break;
                case 1:
                case 2:
                case 3:
                    for (int i = 1; i <= num / iter->first; ++i) {
                        roman.push_back(iter->second);    
                    };
                    break;
                case 4:
                    // last was 5x
                    if (roman.back() == prev(iter)->second) {
                        roman.pop_back();
                        roman.push_back(iter->second);
                        roman.push_back(prev(prev(iter))->second);
                    }
                    // last was not 5x
                    else {
                        roman.push_back(iter->second);
                        roman.push_back(prev(iter)->second);
                    }
                    break;
                default:
                    break;
                    
            }
            num %= iter->first;
        } 
        return roman;
    }
};

