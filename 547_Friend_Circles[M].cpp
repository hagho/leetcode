class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(), false);
        int res = 0;
        for(int i = 0; i < M.size(); i++) {
            if (!visited[i]) {
                res++;
                dfs(M, visited, i);
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++) {
            if (M[i][j] && i != j && !visited[j]) {
                dfs(M, visited, j);
            }
        }
    }
};