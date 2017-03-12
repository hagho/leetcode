class Solution {
public:
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int id = 0;
    unordered_map<string, string> m;//LongURL to TinyURL
    unordered_map<int, string> idm; //id to LongURL
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (m.find(longUrl) != m.end()) {
            return m[longUrl];
        }
        id++;
        string res;
        int count = id;
        while(count > 0) {
            res =  dict[count % 62] + res;
            count /= 62;
        }
        if (res.size() < 6) {
            res = '0'+ res;
        }
        m[longUrl] = res;
        idm[id] =longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id = 0;
        for (int i = 0; i < shortUrl.size(); i++) {
            id = id * 62 + (int)dict.find(shortUrl[i]);

        }
        if (idm.find(id) != idm.end()) {
            return idm[id];
        }
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));