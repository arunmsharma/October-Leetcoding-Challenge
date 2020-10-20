//Day 19
class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        //every col must have a common element either above or below
        // 2 1 2 4 2 2
        // 5 2 6 2 3 2
        // first col have 2 and 5 so current candidates are 2 and 5
        // now second col have 2 so 2 is our candidate only 
		// keep doing this futher.....
		
        // a1 a2 a3 ...  an
        // b1 b2 b3 ..   bn
        // choose a1 and b1 .. keep on doing untill we can find a1 or b1 in every col
        int n = a.size();
        if(n<=1){
            return 0;
        }
        int cana = a[0],canb = b[0];
        for(int i=1;i<n;i++){
		//that means cana is no more candidate further
            if(cana!=a[i] and cana!=b[i]){
               cana=-1;
            }
			//that means cana is no more candidate further
            if(canb!=a[i] and canb!=b[i]){
                canb=-1;
            }
			/if no candidate left then return -1
            if(cana==-1 and canb==-1){
                return -1;
            }
        }
        int ansforcana=INT_MAX,ansforcanb=INT_MAX;
		//calculate answer for cana and canb and return minimum for those
        if(canb!=-1){
            int ansa=0,ansb=0; // answer for upper half and lower half and take min of two
            //compare everything with canb
            for(int i=0;i<n;i++){
                if(a[i]!=canb){
                    ansa++;
                }
                if(b[i]!=canb){
                    ansb++;
                }
            }
            ansforcanb = min(ansa,ansb);
        }
         if(cana!=-1){
            int ansa=0,ansb=0; // answer for upper half and lower half and take min of two
            //compare everything with cana
            for(int i=0;i<n;i++){
                if(a[i]!=cana){
                    ansa++;
                }
                if(b[i]!=cana){
                    ansb++;
                }
            }
            ansforcana = min(ansa,ansb);
        }
        return min(ansforcana,ansforcanb);
    }
};
