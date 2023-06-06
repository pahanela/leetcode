class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> rtrn;
        
        auto max_it = max_element(std::begin(candies), std::end(candies));
        
        for (int candy : candies) {
            if (candy + extraCandies >= *max_it)
                rtrn.push_back(true);
            else
                rtrn.push_back(false);
        }
        return rtrn;
    }
};

