class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, int> dict;
        int index = 0;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if (dict.find(temp) == dict.end()) {
                dict[temp] = index++;
                res.push_back(vector<string>());
            } 
            res[dict[temp]].push_back(strs[i]);
        }
        return res;
    }
};