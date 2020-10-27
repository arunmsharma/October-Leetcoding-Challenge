//Day 26
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double mat[101][101];
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                mat[i][j]=0.0;
            }
        }
        mat[0][0]=poured;
        
        for(int row=0;row<=query_row;row++){
            for(int col=0;col<=row;col++){
                double quant = (mat[row][col]-1.0)/2.0;
                if(quant>0){
                    mat[row+1][col]+=quant;
                    mat[row+1][col+1]+=quant;
                }
            }
        }
        
        if(mat[query_row][query_glass]>1.0){
            return 1.0;
        }
        else{
            return mat[query_row][query_glass];
        }
    }
};
