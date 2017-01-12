class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        //map<char, string> telephone;
        telephone_init(telephone);
        fun(result, digits, "", 0);
        return result;
    }
private:
    void fun(vector<string>& result, string& digits, string curstr, int size) {
        if (size == digits.size()) {
            if (size == 0) {
                return;
            }
            result.push_back(curstr);
            return;
        }
        string candicate = telephone[digits[size]];
        for (int i = 0; i < candicate.size(); ++i) {
            fun(result, digits, curstr+candicate[i], size + 1);
        }
    }

    void telephone_init(map<char, string>& telephone) {
        telephone['1'] = "";
        telephone['2'] = "abc";
        telephone['3'] = "def";
        telephone['4'] = "ghi";
        telephone['5'] = "jkl";
        telephone['6'] = "mno";
        telephone['7'] = "pqrs";
        telephone['8'] = "tuv";
        telephone['9'] = "wxyz";
    }
    map<char, string> telephone;
};