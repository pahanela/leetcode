class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int element = 0;
        for (auto & num : nums)
            element ^= num;
        return element;
    }   
};


/**
 Brute force solution
 Beats random % of submissions by runtime, O(1) complexity
 Beats only 5% of submissions by memory, O(1) complexity
**/

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         std::vector <int> occurs(60000);
//         for (auto & num : nums)
//             occurs[num + 30000]++;
//         for (int i = 0; i < occurs.size(); i++) {
//             if (occurs[i] == 1) {
//                 return i - 30000;
//             }
//         }
//         return 0;
//     }
// };

