class Solution {
public:
    int numTrees(int n) {
        // int dp[n+1];
        // dp[0]=1;
        // for(int i = 1; i <= n; i++){
        //     dp[i] = 0;
        //     for(int j = 0; j < i; j++){
        //         dp[i]+=dp[j]*dp[i-j-1];
        //     }
        // }
        // return dp[n];
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return int (C);

    }
};