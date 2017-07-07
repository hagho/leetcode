class Solution {
public:
    // int hIndex(vector<int>& citations) {
    //     int n = citations.size();
    //     for (int i = n; i >= 0 ; i--) {
    //         int count = 0;
    //         for (int j = 0; j < citations.size(); j++) {
    //             if (citations[j] >= i) {
    //                 count++;
    //                 if (count >= i) {
    //                     return i;
    //                 }
    //             }
    //         }
    //     }
    // }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= citations.size() - i) {
                return citations.size() - i;
            }
        }
        return 0;   
    }
};