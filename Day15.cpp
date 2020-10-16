//Day15
class Solution {
public:
    void reverse(vector<int>&nums,int l,int r){
        while(l<=r){
            swap(nums[l],nums[r]);
            ++l;
            --r;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k%=n;
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};
