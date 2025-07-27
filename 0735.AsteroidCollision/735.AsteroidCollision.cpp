class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> rtrn;

        for (int i = 0; i < asteroids.size(); ) {
            
            // if there are no asteroids on the left
            if (rtrn.size() == 0) {
                rtrn.push_back(asteroids[i++]);
                continue;
            }

            // if both asteroids are going in the same direction, do nothing
            if ((rtrn.back() > 0 && asteroids[i] > 0) || rtrn.back() < 0) {
                rtrn.push_back(asteroids[i++]);
                continue;
            }
            // if asteroids collide, leave the large one
            if (rtrn.back() > 0 && asteroids[i] < 0 && rtrn.back() != abs(asteroids[i])) {
                if (rtrn.back() < abs(asteroids[i]))
                    rtrn.pop_back();
                else if (rtrn.back() > abs(asteroids[i]))
                    i++;
                continue;
            }
            // if asteroids are of the same size remove both
            if (rtrn.back() == abs(asteroids[i])) {
                rtrn.pop_back();
                i++;
            }
        }

        return rtrn; 
    }
};

