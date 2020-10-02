//day 2
class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>&candidates,int start,int sum,vector<int>p){
        if(sum==0){
            ans.push_back(p);
            return;
        }
        if(sum<0){
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]<=sum){
                vector<int>path=p;
                path.push_back(candidates[i]);
                fun(candidates,i,sum-candidates[i],path);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        fun(candidates,0,target,{});
        return ans;
    }
};
