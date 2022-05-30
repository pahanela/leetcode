class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> rtrn;
        unordered_map<int, short int> hashmap;
        for (unsigned short i = 0; i < nums.size(); ++i) {
            if (hashmap.count(target - nums[i])) {
                rtrn.push_back(hashmap.at(target - nums[i]));
                rtrn.push_back(i);
                break;
            }   
            else
                hashmap.insert({nums[i], i});
        }
        return rtrn;
    }
};

