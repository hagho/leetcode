class Solution {
public:
    string reverseStr(string s, int k) {
        int temp = 0;
        while (temp < s.size()) {
            fun(s, temp, temp+ k - 1);
            temp += 2 * k;
        }
        return s;
    }

private:
    void fun(string &s, int st, int ed) {
        if (ed >= s.size()) {
            ed = s.size() - 1;
        }
        while (st < ed) {
            swap(s[st++], s[ed--]);
        }
        return ;
    }
};