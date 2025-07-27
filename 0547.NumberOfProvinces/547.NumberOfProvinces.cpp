class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numCities = isConnected.size();
        vector<vector<int>> provinces(numCities, vector<int>(numCities));

        // let every city be its own province at first
        for (int city = 0; city < numCities; city++)
            provinces[city][0] = city;

        // merge provinces if connected
        for (int i = 0; i < numCities; i++) {
            for (int j = i + 1; j < numCities; j++) {
                if (isConnected[i][j]) {
                    int src = getIndex(provinces, j);
                    int dst = getIndex(provinces, i);
                    if (src != dst) {
                        provinces[dst].insert( \
                            provinces[dst].end(), \
                            provinces[src].begin(), \
                            provinces[src].end());
                        provinces[src].clear();
                        provinces[src].push_back(-1);  // flag merged province
                        provinces[src].push_back(dst);  // indicated direction of merge
                    }
                }
            }
        }

        int numProvinces = 0;
        for (auto & province : provinces) {
            if (province[0] != -1)
                numProvinces++;
        }
        return numProvinces;
    }

    int getIndex(vector<vector<int>> & elements, int index) {
        int rtrn = index;
        if (elements[index][0] == -1)
            rtrn = getIndex(elements, elements[index][1]);
        return rtrn;
    }
};

