class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        map<int, vector<int>> child;
        for (int i = 0; i < prerequisites.size(); i++) {
            degree[prerequisites[i].first]++;
            child[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        bool flag = true;
        vector<bool> courses(numCourses, true);
        while (flag) {
            flag = false;
            for (int i = 0;i < degree.size(); i++) {
                if (degree[i] == 0 && courses[i]) {
                    flag = true;
                    courses[i] = false;
                    for (int j = 0; j < child[i].size(); j++) {
                        degree[child[i][j]]--;
                    }
                }
            }
        }
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i] != 0) {
                return false;
            }
        }
        return true;
    }
};