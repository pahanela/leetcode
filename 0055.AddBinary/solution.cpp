class Solution {
public:
    string addBinary(string a, string b) {
        string rtrn = "";
        int idxA = a.length() - 1;
        int idxB = b.length() - 1;
        int sum = 0;
        while (idxA >= 0 || idxB >= 0) {
            // calculate the sum of characters and carryover
            if (idxA >= 0)
                sum += a.at(idxA) - '0';
            if (idxB >= 0)
                sum += b.at(idxB) - '0';
            // process result
            switch (sum) {
                case 0b00:
                    rtrn.insert(0, 1, '0');
                    break;
                case 0b01:
                    rtrn.insert(0, 1, '1');
                    sum = 0;
                    break;
                case 0b10:
                    rtrn.insert(0, 1, '0');
                    sum = 1;
                    break;
                case 0b11:
                    rtrn.insert(0, 1, '1');
                    sum = 1;
                default:
                    // unexpected result for sum calculation
                    break;
            }
            idxA--;
            idxB--;
        }
        // there is still one carry over 1
        if (sum == 1)
            rtrn.insert(0, 1, '1');
        return rtrn;
    }
};

