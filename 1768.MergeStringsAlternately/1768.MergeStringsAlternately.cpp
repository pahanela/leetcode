class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string rtrnString = "";
        string::iterator it1 = word1.begin();
        string::iterator it2 = word2.begin();
        
        while(it1 != word1.end() && it2 != word2.end()) {
            rtrnString.push_back(*it1);
            rtrnString.push_back(*it2);
            it1++;
            it2++;
        }
        
        while(it1 != word1.end()){
            rtrnString.push_back(*it1);
            it1++;
        }
            

        while(it2 != word2.end()) {
            rtrnString.push_back(*it2);
            it2++;
        }

        return rtrnString;    
    }
};

