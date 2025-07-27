class Solution {
public:
    string reverseVowels(string s) {
        int pLeft = 0;
        int pRight = s.length() - 1;
        
        while (pLeft < pRight) {
            if (pLeft < pRight && isVowel(s[pLeft]) && isVowel(s[pRight])) {
                swap(s[pLeft], s[pRight]);
                pLeft++;
                pRight--;
            }
            if (!isVowel(s[pLeft]))
                pLeft++;
            if (!isVowel(s[pRight]))
                pRight--;
        }
        return s;
    }
    
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || \
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
};
