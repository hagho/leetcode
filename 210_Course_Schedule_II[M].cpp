class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<int> indegree(numCourses, 0);
        queue<int> zeroOfIndegree;
        set<pair<int, int>> s(prerequisites.begin(), prerequisites.end());
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i].first]++;
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) { 
                zeroOfIndegree.push(i);
            }
        }
        while (!zeroOfIndegree.empty()) {
            int temp = zeroOfIndegree.front();
            res.push_back(zeroOfIndegree.front());
            zeroOfIndegree.pop();
            for(auto i = s.begin(); i != s.end();) {
                if (i->second == temp) {
                    indegree[i->first]--;
                    if (indegree[i->first] == 0) { 
                        zeroOfIndegree.push(i->first);
                    }
                    i = s.erase(i);
                } else{
                    i++;
                }
            }
        }
        if (!s.empty()) {
            return vector<int>();
        }
        return res;
    }
};