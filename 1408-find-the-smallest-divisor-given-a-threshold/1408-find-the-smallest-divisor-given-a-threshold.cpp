class Solution {
public:
    int binSearch(vector<int>& nums, int& divisor) {
        int result = 0;
        for (int& num : nums) {
            result += ceil((1.0 * num) / divisor);
        }
        return result;
    }
    

//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n = nums.size();
//         int res = INT_MAX;
//         int lar = nums[0];
//         for (int i = 1; i < n; i++) {
//             if (nums[i] >= lar) {
//                 lar = nums[i];
//             }
//         }
//         int l = 0, h = lar;
//         int ans = 0;
//         while (l <= h) {
//             int mid = h + ((l - h) / 2);
//             long long result = binSearch(nums, mid);
//             if (result <= threshold) {
//                 ans = mid;
//                 h = mid - 1;
//             }
//             else {
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }
// };



    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        // Iterate using binary search on all divisors.
        while (low <= high) {
            int mid = (low + high) / 2;
            int result = binSearch(nums, mid);
            // If current divisor does not exceed threshold, 
            // then it can be our answer, but also try smaller divisors
            // thus change search space to left half.
            if (result <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, we need a bigger divisor to reduce the result sum
            // thus change search space to right half.
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};



// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n = nums.size();
//         int res = INT_MAX;
//         int lar = nums[0];
//         for(int i = 1; i < n; i++){
//             if(nums[i]>=lar){
//                 lar = nums[i];
//             }
//         }    
//         // int div = lar;
//         for(int i = lar; i >= 1; i--){
//             int ans = 0;
//             for(int j = 0; j < n; j++){
//                 ans += ceil(static_cast<double>(nums[j]) / i);
//             }
//             if(ans<=threshold){
//                 res = min(res,i);
//             }
//             else{
//                 break;
//             }
//             cout<<i<<"";
//         }

//         return res;  
//     }

// };
