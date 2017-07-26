class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.empty() || s.size() < 10) {
            return res;
        }
        unordered_map<string, int> m;
        for (int i = 0; i < s.size() - 9; i++) {
            string sub = s.substr(i, 10);
            if (m.find(sub) != m.end()) {
                if (m[sub] == 1) {
                    res.push_back(sub);
                    m[sub]++;
                }
            } else {
                m[sub] = 1;
            }
        }
        return res;
    }
};