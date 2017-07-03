class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> s;
        preorder += ",";
        string tmp;
        int top = -1;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] != ',') {
                tmp += preorder[i];
                continue;
            }
            s.push_back(tmp);
            tmp = "";
            top++;
            while (s.size() > 1 && s[top] == "#" && s[top - 1] == "#") {
                s.pop_back();
                top--;
                s.pop_back();
                top--;
                if (top < 0) {
                    return false;
                }
                s.pop_back();
                s.push_back("#");
            }
        }
        if (s.size() == 1 && s[0] == "#") {
            return true;
        }
        return false;
    }
};