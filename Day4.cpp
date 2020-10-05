//Day 4
class Solution {
public:
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        for(int i=0;i<intervals.size();i++){
            for(int j=0;j<intervals.size();j++){
                if(i!=j){
                    if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1]){
                        ans++;
                        break;
                    }
                }
            }
        }
        return intervals.size()-ans;
    }
};
