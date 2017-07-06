class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int n = secret.size();
        multiset<char> a;
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                a.insert(secret[i]);
            }
        }
        int cow = 0;
        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i]) {
                multiset<char>::iterator p = a.find(guess[i]);
                if (p != a.end()) {
                    a.erase(p);
                    cow++;
                }
            }
        }
        string res = "";
        res += to_string(bull);
        res += 'A';
        res += to_string(cow);
        res += 'B';
        return res;
    }
};