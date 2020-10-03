//day 3
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(i<nums.size()-1) if(nums[i]==nums[i+1]) continue;
            
            while(nums[i]-nums[j]>k){
                ++j;
            }
            if(nums[i]-nums[j]==k && i!=j){
                ans++;
            }
        }
        return ans;
    }
};
