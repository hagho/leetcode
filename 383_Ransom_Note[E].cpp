class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //set<char> r(ransomNote.begin(), ransomNote.end());
        multiset<char> m(magazine.begin(), magazine.end());
        for (int i = 0; i < ransomNote.size(); i++) {
            auto itor = m.find(ransomNote[i]);
            if (itor != m.end()) {
                m.erase(itor);
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};