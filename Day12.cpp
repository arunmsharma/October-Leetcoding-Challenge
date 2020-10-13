//Buddy Strings
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size()){
            return false;
        }
        int count =0,n = A.length(),f=0;
        string str1,str2;
        int freq[26]={0};
        for(int i=0;i<n;i++){
            freq[A[i]-'a']++;
            if(freq[A[i]-'a']==2){
                f=1;
            }
            if(A[i]==B[i]){
                continue;
            }
            else{
                count++;
                str1+=A[i];
                str2+=B[i];
            }
        }
        if((count<=0 && f) || (count==2 && str1[0]==str2[1] && str1[1]==str2[0])){
            return true;
        }
        return false;
    }
};
