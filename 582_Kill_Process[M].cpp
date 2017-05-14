class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int,vector<int>> e;
        int n=pid.size();
        for ( int i=0; i<n; i++ ) e[ppid[i]].push_back(pid[i]);
        vector<int> q;
        q.push_back(kill);
        for ( int i=0; i<q.size(); i++ ) {
            int x=q[i];
            for ( int j:e[x] ) q.push_back(j);
        }
        return q;
    }
};