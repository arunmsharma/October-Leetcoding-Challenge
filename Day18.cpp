//Day 18
class Solution {
public:
   int maxProfit(int k, vector<int>& prices) {
        int n=prices.size(),b=0;
        if(n==0 || n==1)
            return 0;
        if((n/2)<=k)            //it can be solved in order of n time
        {
            int i = 0,ans=0; 
            while (i < n - 1) { 
                while ((i < n - 1) && (prices[i + 1] <= prices[i])) 
                    i++; 
                if (i == n - 1) 
                    break; 
                int buy = i++; 
                while ((i < n) && (prices[i] >= prices[i - 1])) 
                    i++; 
                int sell = i - 1; 
                ans+=prices[sell]-prices[buy];

            } 
            return ans;
        }
        
        int dp[2][n];
        for(int i=0;i<n;i++)
            dp[0][i]=0;
        dp[1][0]=0;
        for(int i=1;i<=k;i++)
        {
            b=1-b;
            int l=-prices[0];
            for(int j=1;j<n;j++)
            {
                dp[b][j]=max(dp[b][j-1],l+prices[j]);
                l=max(l,dp[1-b][j-1]-prices[j]);
            }
        }
        return dp[b][n-1];

    }
};
