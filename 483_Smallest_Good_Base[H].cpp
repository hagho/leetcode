class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stol(n);
        unsigned long long length = log2(num) + 1;
        while (length > 2) {
            unsigned long long result = findAns(length, num);
            if (result != -1) {
                return to_string(result);
            }
            length--;
        }

        return to_string(num - 1);
    }
private:
    unsigned long long findAns(unsigned long long length, unsigned long long num) {
        unsigned long long st = 0;
        unsigned long long ed = num;
        while (st <= ed) {
            unsigned long long mid = st + ( ed - st ) / 2;
            unsigned long long target = getAnsOfBase(length, mid);
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
    unsigned long long getAnsOfBase(unsigned long long length, unsigned long long mid) {
        unsigned long long ans = 1;
        while (length > 1) {
            ans = ans * mid + 1;
            length--;
        }
        return ans;
    }
};