//Day 24
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int l=0,r=tokens.size(),answer=0;
        while(l<r){
            if(P>=tokens[l]){
                P-=tokens[l];
                answer++;
                l++;
            }
            else if(l+1<r and answer>=1){
                --r;
                P+=tokens[r];
                answer--;
            }
            else{
                return answer;
            }
        }
        return answer;
    }
};
