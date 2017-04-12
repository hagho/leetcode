class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (auto i = m.begin(); i != m.end(); i++) {
            pq.push(make_pair(i->second, i->first));
            if (pq.size() > (int)m.size()-k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};