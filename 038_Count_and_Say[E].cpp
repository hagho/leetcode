class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; i++) {
            string tmp = "";
            int count = 1;
            char tmpchar = res[0];
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == tmpchar) {
                    count++;
                } else {
                    tmp += to_string(count) + tmpchar;
                    tmpchar = res[j];
                    count = 1;
                }
            }
            tmp += to_string(count) + tmpchar;
            res = tmp;
        }
        return res;
    }
};