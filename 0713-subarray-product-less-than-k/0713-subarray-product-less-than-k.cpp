class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int n = nums.size();

        int i=0,j=0;
        long p=1;
        int ans=0;
    
        while(i<n&&j<n){
            p=p*nums[j];
            while(p>=k&&i<=j){
                p=p/nums[i];
                i++;
            }
            if(p<k)
            ans+=j-i+1;
            j++;
        }
        
        return ans;
    }
};