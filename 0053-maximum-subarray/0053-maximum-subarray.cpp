class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            sum = sum + nums[i];

            maxi = max(maxi,sum);

            if(sum<0){
                sum = 0;
            }
            
        }
        return maxi;

        // int n = nums.size();
        // int res = nums[0];
        // int maxending = nums[0];
        // for(int i = 1; i < n; i++){
        //     maxending = max(maxending+nums[i], nums[i]);
        //     res=max(maxending,res);
        // }
        // return res;

        
            
    }
};