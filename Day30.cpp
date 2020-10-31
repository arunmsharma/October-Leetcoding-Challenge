//Day 30
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(dp[i]==dp[j]+1){
                        cnt[i]+=cnt[j];
                    }
                }
               
            }
        }
        int maxx = *max_element(dp.begin(),dp.end());
        int answer=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxx){
                answer += cnt[i];
            }
        }
        return answer;
    }
    
};
