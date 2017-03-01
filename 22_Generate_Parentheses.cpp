#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> p[n + 1];
        //以下初始方法只适用于C++11后
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