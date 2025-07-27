class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numRooms = rooms.size();
        vector<bool> roomsVisited(numRooms, false);  // container to flag visited rooms
        vector<int> keyring;  // current keys on hand
        int sumVisited = 0;  // number of visited rooms so far
        keyring.insert(keyring.end(), rooms[0].begin(), rooms[0].end());
        roomsVisited[0] = true;
        sumVisited++;
        while (!keyring.empty()) {
            int key = keyring.back();
            keyring.pop_back();
            if (!roomsVisited[key]) {
                roomsVisited[key] = true;
                sumVisited++;
                keyring.insert(keyring.end(), rooms[key].begin(), rooms[key].end());
            }
        }
        if (sumVisited < numRooms)
            return false;
        return true;
    }
};

