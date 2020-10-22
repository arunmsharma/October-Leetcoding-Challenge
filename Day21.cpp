//Day 21
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
       stack<int>st;
        int n = arr.size();
        st.push(arr[0]);
            for(int i=1;i<n;i++){
                if(arr[i]<0){
                    int ok=0;
                    while(st.empty()==false and st.top()>0){
                        if(abs(arr[i])>st.top()){
                            st.pop();
                        }
                        else if(abs(arr[i])<st.top()){
                            ok=1;
                            break;
                        }
                        else{
                            ok=1;
                            st.pop();
                            break;
                            }
                        }
                        if(ok==0){
                            st.push(arr[i]);
                        }
                }
                else{
                    st.push(arr[i]);
                }
            }
        
        vector<int>ans;
        while(st.empty()==false){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
