class Solution {
public:
    int rob(vector<int>& nums) {
        
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
    }
};