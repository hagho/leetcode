// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int st = 1;
        int ed = n;
        while (st < ed) {
            int mid = st + (ed - st) / 2;
            if (guess(mid) == 1) {
                st = mid + 1;
            } else if (guess(mid) == -1) {
                ed = mid - 1;
            }
            else {
                return mid;
            }
        }    
        return st;
    }
};