//Day 23
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //1.order of n^2 is trivial i can use two loops
        //2.i<j<k and nums[i]<nums[k]>nums[j]
        
        
        // obeserving nums[j]>nums[i] and nums[j]>nums[k]
        // fix j
        // and i know nums[k]>nums[i] 
        // therefore i will choose largest number on the right which is smaller than nums[j]
        // and smallest number on the left which is smaller than j
        // then if nums[k]>nums[i] then for sure i have a pair
         
        int n = nums.size();
        int left[n];
        left[0]=INT_MIN;
        int min = nums[0];
        for(int j=1;j<n;j++){
            if(min>nums[j]){
                //that means there is not min element on the left sides which is smaller than it
                left[j]=INT_MIN;
                min = nums[j];
            }
            else{
                left[j]=min;
            }
        }
        //now how to check for largest smaller element(smaller than nums[j]) on right of every element
        int right[n];
        right[n-1]=INT_MAX;
        //i can maintain a set and find lower bound of that number(the number which is just greater than or equal to some number) and than compare the number previous to lower bound(bcz they will be smaller) and then largest of them
        set<int>st;
        st.insert(nums[n-1]);
        for(int j=n-2;j>=0;j--){
            auto it =lower_bound(st.begin(),st.end(),nums[j]);
            // cout<<*it<<endl;
            if(it==st.begin()){
                right[j]=INT_MAX;
            }
            else{
                it--;
                right[j]=*it;
            }
            st.insert(nums[j]);
        }
        
        //now the main part
        for(int j=0;j<n;j++){
            if(left[j]!=INT_MIN and right[j]!=INT_MAX){
                if(right[j]>left[j]){
                    return true;
                }
            }
        }
        return false;
    }
};
