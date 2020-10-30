//Day 29
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int>v;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1)
            v.push_back(i);
        }
        int answer=v[0];
        for(int i=1;i<v.size();i++){
            answer=max(answer,(v[i]-v[i-1])/2);
        }
        answer = max(answer,(int)seats.size()-1-v[v.size()-1]);
        return answer;
    }
};
