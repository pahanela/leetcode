class Solution {
public:
    string predictPartyVictory(string senate) {
        int rBan = 0;
        int dBan = 0;
        int size = senate.length();
        int loop = 2 * size;

        for (int i = 0; i < size; i++) {
            if (senate[i] == 'R') {
                if (rBan > 0)
                    rBan--;
                else {
                    senate += 'R';
                    size++;
                    dBan++;
                }
            }
            if (senate[i] == 'D') {
                if (dBan > 0)
                    dBan--;
                else {
                    senate += 'D';
                    size++;
                    rBan++;
                }
            }

            //cout << senate << endl;

            loop--;
            if (loop == 0)
                break;
        }

        if (senate[senate.length() - 1] == 'R')
            return "Radiant";
        else
            return "Dire";
    }
};

