class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtracking(result, n, 0, 0, "");
        return result;
    }
private:    
    void backtracking(vector<string> &result, int n, int left, int right, string parenthese) {
        if (parenthese.size() == 2 * n) {
            result.push_back(parenthese);
            return;
        }
        if (left < n) {
            backtracking(result, n, left + 1, right, parenthese + "(");
        }
        if (right < left) {
            backtracking(result, n, left, right + 1, parenthese + ")");
        }
    }
};

/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> p[n + 1];
        p[0] = vector<string>{""};
        p[1] = vector<string>{"()"};
        for (int i = 2; i <= n; i++) {
            for (int j = 0;j < i; j++) {
                for (int k = 0 ; k < p[i - j - 1].size(); k++) {
                    for (int l = 0;l < p[j].size(); l++) {
                        p[i].push_back("(" + p[i-j-1][k]+ ")" + p[j][l]);
                    }
                }
            }
        }
        return p[n];

    }
};
*/