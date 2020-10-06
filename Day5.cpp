//Day 5
class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0){
            return 1;
        }
        int b = log2(N)+1;
        int num = (1<<b) -1;
        // cout<<num<<endl;
        return num-N;
    }
};
