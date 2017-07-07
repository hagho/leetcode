class Solution {
public:
    int hIndex(vector<int>& citations) {
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= citations.size() - i) {
                return citations.size() - i;
            }
        }
        return 0;
    }
};