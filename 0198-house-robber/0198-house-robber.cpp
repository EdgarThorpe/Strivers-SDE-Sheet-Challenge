class Solution {
public:
    int rob(vector<int>& nums) {
        
        // Space optimized, SC = O(1)

        int n = nums.size();
        
        if(n==1) return nums[0];
        // vector<int>dp(n+1);
        int prev_prev = nums[0];
        int prev=max(nums[0],nums[1]);
        int res = prev;
        for(int i=3;i<=n;i++){
            res=max(prev,prev_prev+nums[i-1]);
            prev_prev = prev;
            prev = res;
        }
        return res;


        // Dp, SC = O(n)

        // int n = nums.size();
        
        // if(n==1) return nums[0];
        // vector<int>dp(n+1);
        // dp[1]=nums[0];
        // dp[2]=max(nums[0],nums[1]);
        // for(int i=3;i<=n;i++){
        //     dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
        // }
        // return dp[n];
    }
};