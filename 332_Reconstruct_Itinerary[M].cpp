class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ticket : tickets) {
            target[ticket.first].insert(ticket.second);
        }
        visit("JFK");
        return vector<string>(res.rbegin(), res.rend());
    }

private:
    map<string, multiset<string>> target;
    vector<string> res;
    void visit(string airport) {
        while (target[airport].size()) {
            string next = *target[airport].begin();
            target[airport].erase(target[airport].begin());
            visit(next);
        }
        res.push_back(airport);
    }
};