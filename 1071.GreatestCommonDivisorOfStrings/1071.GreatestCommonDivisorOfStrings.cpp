class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string commonStr = "";
        string compStr1 = "";
        string compStr2 = "";

        // find largest common prefix
        int i = 0;
        while (str1[i] == str2[i])
            i++;
        commonStr = str1.substr(0, i);

        // while prefix is not empty keep checking and decrease the size if not
        while (!commonStr.empty()) {

            compStr1 = "";
            compStr2 = "";

            if (str1.length() % commonStr.length() == 0 && str2.length() % commonStr.length() == 0) {
                int k1 = str1.length() / commonStr.length();
                int k2 = str2.length() / commonStr.length();

                for (int j1 = 0; j1 < k1; j1++)
                    compStr1.append(commonStr);

                for (int j2 = 0; j2 < k2; j2++)
                    compStr2.append(commonStr);

                if (str1.compare(compStr1) == 0 && str2.compare(compStr2) == 0) {
                    break;
                }

            }

            commonStr.pop_back();
        }

        return commonStr;
    }
};

