class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> numOfOnes;
        for (int i = 0; i <= n; i++) {
            int x = i;
            int count;
            for (count = 0; x; count++)
                x &= x - 1;
            numOfOnes.push_back(count);
        }
        return numOfOnes;
    }
};

