class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int count = 0, arrow = INT_MIN;
        sort(points.begin(), points.end(), mysort);
        for(int i = 0; i<points.size(); i++){
            if(arrow!=INT_MIN && points[i].first<=arrow){continue;} //former arrow shot points[i] 
            arrow = points[i].second; // new arrow shot the end of points[i]
            count++;
        }
        return count;
    }
    static bool mysort(pair<int, int>& a, pair<int, int>& b){
        return a.second==b.second?a.first<b.first:a.second<b.second;
    }
};