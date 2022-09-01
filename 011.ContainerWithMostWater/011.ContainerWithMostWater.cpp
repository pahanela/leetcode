class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int cur_area = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i != j) {
            if (height[i] < height[j]) {
                cur_area = height[i] * abs(i - j);
                i++;
            }
            else {
                cur_area = height[j] * abs(i - j);
                j--;
            }
            if (cur_area > max_area)
                max_area = cur_area;
        }
        return max_area;
    }
};

