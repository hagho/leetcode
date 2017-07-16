class Solution {
public:
    const int base = 1337;
    int superPow(int a, vector<int>& b) {
        if (b.empty()) {
            return 1;
        }
        int last_digit = b.back();
        b.pop_back();
        return Powmod(superPow(a,b), 10) * Powmod(a, last_digit) % base; 
    }
private:
    int Powmod(int a, int k) {//计算a^k mod base的结果
        a %= base;
        int res = 1;
        for (int i = 0; i < k; i++) {
            res = ( res * a ) % base;
        }
        return res;
    }
};