class Solution {
public:
    int countArrangement(int N) {
        int res = 0;
        unordered_map<int, bool> m;
        for (int i = 1;i <= N; i++) {
            m[i] = true;
        }
        backtracking(N, m, 0, res);
        return res;
    }

private:
    void backtracking(int N, unordered_map<int, bool> m,  int deep, int &res) {
        if (deep == N) {
            res++;
            return;
        }
        for (int i = 1;i <= m.size(); i++) {
            if (m[i]==true&&(i%(deep+1)==0||(deep+1)%i==0)) {
                m[i] = false;
               // cout<<i<<endl;
                backtracking(N,m,deep+1,res);
                m[i] = true;
            }
        } 
        /*
        for (unordered_map<int, bool>::iterator itor = m.begin();itor != m.end(); itor++) {
            if (itor->second == true && (itor->first % (deep+1)== 0||(deep+1)%itor->first==0)) {
                itor->second = false;
                cout<<itor->first<<endl;
                backtracking(N, m, deep + 1, res);
            } 
            itor->second = true;
        }
        */
    }

};