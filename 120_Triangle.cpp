class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        std::vector<int> minpath(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                minpath[j] = min(minpath[j], minpath[j + 1]) + triangle[i][j];
            }
        } 
        return minpath[0];
    }
};