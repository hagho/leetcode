class Solution {
public:

    class trie {
        bool isRoot = false;
        trie* l[26] = {};
    public:
        void insert(string& word, int ch, int sz) {
            isRoot |= ch == sz;
            if (!isRoot) { // stop at the shortest root.
                if (l[word[ch] - 'a'] == nullptr) l[word[ch] - 'a'] = new trie();
                l[word[ch] - 'a']->insert(word, ch + 1, sz);
            }
        }
        int root(string& word, int st, int ch, int sz) {
            if (st + ch == sz || word[st + ch] == ' ' || this->isRoot) return ch;
            if (l[word[st + ch] - 'a'] == nullptr) { // root was not found
                while (st + ch < sz && word[st + ch] != ' ') ++ch; // skipping the entire word
                return ch;
            }
            return l[word[st + ch] - 'a']->root(word, st, ch + 1, sz);
        }
    };

    string replaceWords(vector<string>& dict, string sentence) {
        trie t;
        string res;
        for (auto s: dict) {
            t.insert(s, 0, s.size());
        }
        for (int i = 0; i < sentence.size(); ) {
            if (sentence[i] == ' ') {
                res += sentence[i++];
            }
            auto chars = t.root(sentence, i, 0, sentence.size());
            res += sentence.substr(i, chars);
            for (i += chars; i < sentence.size() && sentence[i] != ' '; i++);
        }
        return res;
    }
};