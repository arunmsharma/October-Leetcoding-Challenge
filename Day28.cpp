//Day 28
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>answer;
        for(int i=0;i<nums.size();i++){
            string t;
            t+=to_string(nums[i]);
            int j=i;
            while(i+1<nums.size() and (long long)nums[i+1]-(long long)nums[i]==1){
                i++;
            }
            if(i!=j){
                 t+="->";
                 t+=to_string(nums[i]);
            }
            answer.push_back(t);
            t="";
        }
        return answer;
    }
};
