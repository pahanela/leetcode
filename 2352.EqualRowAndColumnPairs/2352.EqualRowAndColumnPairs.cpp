class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int pairs = 0;
        std::map<vector<int>, std::pair<int, int>> map;
        std::map<vector<int>, std::pair<int, int>>::iterator it;

        // iterate over one side of the grid
        for (int i = 0; i < grid.size(); i++) {
            // count all row occurrences
            it = map.find(grid[i]);
            if (it != map.end())
                it->second.first++;
            else
                map.insert(std::pair<vector<int>, pair<int, int>> (grid[i], std::pair<int, int> (1, 0)));

            // compose column
            std::vector<int> column; 
            for (int j = 0; j < grid.size(); j++)
                column.push_back(grid[j][i]);
            
            // count all column occurrences
            it = map.find(column);
            if (it != map.end())
                it->second.second++;
            else
                map.insert(std::pair<vector<int>, pair<int, int>> (column, std::pair<int, int> (0, 1)));

        }

        // iterate over all occurrences and count pairs by multiplying rows and columns
        for (it = map.begin(); it != map.end(); it++)
            pairs += it->second.first * it->second.second;

        return pairs;
    }
};

