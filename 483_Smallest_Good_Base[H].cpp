class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned __int64 num = stol(n);
        unsigned __int64 length = log2(num) + 1;
        while (length > 2) {
            unsigned __int64 result = findAns(length, num);
            if (result != -1) {
                return to_string(result);
            }
            length--;
        }

        return to_string(num - 1);
    }
private:
    unsigned __int64 findAns(unsigned __int64 length, unsigned __int64 num) {
        unsigned __int64 st = 0;
        unsigned __int64 ed = num;
        while (st <= ed) {
            unsigned __int64 mid = st + ( ed - st ) / 2;
            unsigned __int64 target = getAnsOfBase(length, mid);
            if (target == num) {
                return mid;
            } else if (target > num) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return -1;
    }
    unsigned __int64 getAnsOfBase(unsigned __int64 length, unsigned __int64 mid) {
        unsigned __int64 ans = 1;
        while (length > 1) {
            ans = ans * mid + 1;
            length--;
        }
        return ans;
    }
};