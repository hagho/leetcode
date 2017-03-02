class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        while (right > left) {
            int h = height[right] < height[left] ? height[right] : height[left];
            int temp = ( right - left ) * h;
            if (temp > result) {
                result = temp; 
            }
            if(height[right] > height[left]) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};