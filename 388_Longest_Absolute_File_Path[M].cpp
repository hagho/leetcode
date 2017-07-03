class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0;
        int name = 0;
        int depth = 1;
        map<int, int> level;
        bool isfile = false;
        level[0] = 0;
        for (int i = 0; i < input.size(); i++) {
            while (input[i] == '\t') {
                depth++;
                i++;
            }
            while (input[i] != '\n' && i < input.size()) {
                if (input[i] == '.') {
                    isfile = true;
                }
                name++;
                i++;
            }
            if (isfile) {
                res = max(res, level[depth] + name);
            } else {
                level[depth + 1] = level[depth] + name + 1; 
            }
            name = 0;
            depth = 1;
            isfile = false;
        }
        return res;

    }
};