class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        long nn = n;
        if (nn < 0) {
            nn = -nn;
            x = 1 / x;
            cout<<n<< "  "<< x<<endl;
        }
        return ( nn % 2 == 0 )? myPow(x * x, nn / 2) : x * myPow(x * x, nn / 2);
    }
};