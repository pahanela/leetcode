class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool space;
        
        if (flowerbed[0] == 0)
            space = true;
        else
            space = false;
        
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (n <= 0)
                break;
            if (flowerbed[i])
                space = false;
            else {
                if (i + 1 < flowerbed.size()) {
                    if (space && !flowerbed[i + 1]) {
                        space = false;
                        n--;
                    }
                    else
                        space = true;
                }
                else
                {
                    if (space)
                        n--;
                    else
                        space = true;
                }
            }
        }
        
        if (n > 0)
            return false;
        else
            return true;
    }
};
