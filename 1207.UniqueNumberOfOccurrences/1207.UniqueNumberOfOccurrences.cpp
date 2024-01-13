class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool rtrn = true;

        // map the occurrences of values
        vector<int> occurs (2001, 0);
        for (int i = 0; i < arr.size(); i++)
            occurs[arr[i] + 1000]++;

        // map the number of occurrences
        vector<int> uniqs (1001, 0);
        for (int j = 0; j < occurs.size(); j++) {
            if (occurs[j] > 0)
                uniqs[occurs[j]]++;
        }

        // check the uniqueness condition
        for (int u : uniqs) {
            if (u > 1) {
                rtrn = false;
                break;
            }
        }

        return rtrn;
    }
};

