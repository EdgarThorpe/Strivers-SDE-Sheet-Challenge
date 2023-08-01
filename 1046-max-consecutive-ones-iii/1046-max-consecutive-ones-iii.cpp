class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int count = 0;
        int i = 0, j = 0;
        while(j<n){
            if(nums[j]==0){
                count++;
                // j++;
            }
            if(count>k){
                if(nums[i]==0){
                    count--;
                }
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};