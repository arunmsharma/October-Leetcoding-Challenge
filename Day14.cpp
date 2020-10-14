//day 14
class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return arr[0];
        }
        vector<int>dp1(n,0),dp2(n,0);
        dp1[0]=arr[0];
        dp1[1]=max(arr[0],arr[1]);
        if(n==2){
            return max(arr[0],arr[1]);
        }
        for(int i=2;i<n-1;i++){
            dp1[i]=max(dp1[i-1],dp1[i-2]+arr[i]);
        }
        
        dp2[1]=arr[1];
        for(int i=2;i<n;i++){
            dp2[i]=max(dp2[i-1],dp2[i-2]+arr[i]);
        }
        
        return max({*max_element(dp1.begin(),dp1.end()),*max_element(dp2.begin(),dp2.end())});
    }
};
