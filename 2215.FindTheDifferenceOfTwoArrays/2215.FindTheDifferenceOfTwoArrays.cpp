class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer1;
        vector<int> answer2;

        vector<int> map1(2001, 0);
        vector<int> map2(2001, 0);

        for (int i = 0; i < nums1.size(); i++)
            map1[nums1[i] + 1000] = 1;

        for (int i = 0; i < nums2.size(); i++)
            map2[nums2[i] + 1000] = 1;

        for (int i = 0; i < map1.size(); i++) {
            if (map1[i] && !map2[i])
                answer1.push_back(i - 1000);
            else if (!map1[i] && map2[i])
                answer2.push_back(i - 1000);
        }

        vector<vector<int>> rtrn;
        rtrn.push_back(answer1);
        rtrn.push_back(answer2);

        return rtrn;
    }
};

