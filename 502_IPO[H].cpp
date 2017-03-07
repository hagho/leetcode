class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> low;
        multiset<pair<int,int>> high;
        for (int i = 0;i < Profits.size(); i++) {
            if (Profits[i] > 0 && Capital[i] <= W) {
                low.push(Profits[i]);
            } else {
                high.insert(pair<int,int>(Capital[i], Profits[i]));
            }
        }
        while (k-- && low.size()) {
            W += low.top();
            low.pop();
            for (auto i = high.begin(); high.size() && i->first <=W; i = high.erase(i)) {
                low.push(i->second);
            }
        }
        return W;
    }
};