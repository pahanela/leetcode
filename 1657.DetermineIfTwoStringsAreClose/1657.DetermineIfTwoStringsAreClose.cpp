class Solution {
public:
    bool closeStrings(string word1, string word2) {
        bool rtrn = true;

        // if strings are of different length they cannot be close
        if (word1.length() != word2.length())
            return false;

        // map all the letters in the 1st and the 2nd strings
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);
        for (int i = 0; i < word1.length(); i++) {
            map1[word1[i] - 97]++;
            map2[word2[i] - 97]++;
        }

        // check if all letters are present in both strings
        for (int i = 0; i < map1.size(); i++) {
            if (map1[i] == 0 && map2[i] == 0)
                continue;
            else if (map1[i] > 0 && map2[i] > 0)
                continue;
            else
                return false;
        }

        // map all freqs in the 1st and the 2nd string
        vector<int> freqs1;
        vector<int> freqs2;
        for (int i = 0; i < map1.size(); i++) {
            freqs1.push_back(map1[i]);
            freqs2.push_back(map2[i]);
        }

        // check if frequencies are identical
        std::sort (freqs1.begin(), freqs1.end());
        std::sort (freqs2.begin(), freqs2.end());
        for (int i = 0; i < freqs1.size(); i++) {
            if (freqs1[i] != freqs2[i]) {
                rtrn = false;
                break;
            }
        }

        return rtrn;
    }
};

