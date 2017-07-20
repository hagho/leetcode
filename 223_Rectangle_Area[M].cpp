class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total = ( C - A ) * ( D - B ) + ( G - E ) * ( H - F );
        if (C <= E || G <= A || F >= D || B >= H) {
            return total;
        }
        return total - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
    }
};