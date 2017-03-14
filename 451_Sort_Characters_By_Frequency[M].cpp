class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        });
        return s;
    }
};

/*
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

struct myClass {
        myClass() {
            a = '\0';
            frequency = 0;
            position = 0;
        }
        myClass(char aa, int f, int p) {
            a = aa;
            frequency = f;
            position = p;
        }
        char a;
        int frequency;
        int position;
};

bool operator<(const myClass& A, const myClass& B) {
    if (A.frequency < B.frequency) {
        return true;
    } else {
        return A.position > B.position;
    }
}
class Solution {
public:
    string frequencySort(string s) {
        map<char, myClass> m;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = myClass(s[i], 1, i);
            } else {
                m[s[i]].frequency++;
            }
        }
        cout<<(s['t']).frequency<<endl;
        cout<<s['r'].frequency<<endl;
        cout<<s['e'].frequency<<endl;
        priority_queue<myClass> pq;
        for (auto itor = m.begin(); itor != m.end(); itor++) {
            pq.push(itor->second);
        }
        string res;
        while (!pq.empty()) {
            myClass temp  = pq.top();
            for(int i = 0; i < temp.frequency; i++) {
                res+=temp.a;
            }
            pq.pop();
        }
        return res;
    }

};
*/
