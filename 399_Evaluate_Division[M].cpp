class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> m;
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            string s1 = equations[i].first, s2 = equations[i].second;
            if (m.count(s1) == 0 && m.count(s2) == 0) {
                m[s1] = new Node();
                m[s2] = new Node();
                m[s1]->value = values[i];
                m[s2]->value = 1;
                m[s1]->parent = m[s2];  
            } else if (m.count(s1) == 0) {
                m[s1] = new Node();
                m[s1]->value = m[s2]->value * values[i];
                m[s1]->parent = m[s2];
            } else if(m.count(s2) == 0) {
                m[s2] = new Node();
                m[s2]->value = m[s1]->value / values[i];
                m[s2]->parent = m[s1];
            } else {
                unionNodes(m[s1], m[s2], values[i], m);
            }

        }
        for (auto query : queries) {
            if (m.count(query.first) == 0 || m.count(query.second) == 0 || findParent(m[query.first]) != findParent(m[query.second]))
                res.push_back(-1);
            else
                res.push_back(m[query.first] -> value / m[query.second] -> value);
        }
        return res;
    }
private:
    struct Node {
        Node* parent;
        double value;
        Node() {
            parent = this;
        }
    };

    void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
        double ratio = node2 -> value * num / node1 -> value;
        for (auto it = map.begin(); it != map.end(); it ++)
            if (findParent(it -> second) == parent1)
                it -> second -> value *= ratio;
        parent1 -> parent = parent2;
    }

    Node* findParent(Node* node) {
        if (node -> parent == node)
            return node;
        node -> parent = findParent(node -> parent);
        return node -> parent;
    }
};