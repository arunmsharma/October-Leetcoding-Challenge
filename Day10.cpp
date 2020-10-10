//Day 10
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n==0){
            return 0;
        }
        sort(points.begin(),points.end(),[](auto &p1,auto &p2){
            return p1[1]<p2[1];
        });
        int last = points[0][1];
        
        int ans = 1;
        for(auto point:points){
            if(point[0]<=last){
                continue;
            }
            ans ++;
            last = point[1];
        }
        return ans;
    }
};
