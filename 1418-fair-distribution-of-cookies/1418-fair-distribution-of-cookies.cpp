 class Solution {
public:
    int dfs(int i, vector<int>& distribute, vector<int>& cookies, int k, int zeroCount) {
        // If there are not enough cookies remaining, return INT_MAX 
        // as it leads to an invalid distribution.
        if (cookies.size() - i < zeroCount) {
            return INT_MAX;
        }

        // After distributing all cookies, return the unfairness of this
        // distribution.
        if (i == cookies.size()) {
            return *max_element(distribute.begin(), distribute.end());
        }

        // Try to distribute the i-th cookie to each child, and update answer
        // as the minimum unfairness in these distributions.
        int answer = INT_MAX;
        for (int j = 0; j < k; ++j) {
            zeroCount -= distribute[j] == 0 ? 1 : 0;
            distribute[j] += cookies[i];
            
            // Recursively distribute the next cookie.
            answer = min(answer, dfs(i + 1, distribute, cookies, k, zeroCount)); 
            
            distribute[j] -= cookies[i];
            zeroCount += distribute[j] == 0 ? 1 : 0;
        }
        
        return answer;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k, 0);

        return dfs(0, distribute, cookies, k, k);
    }
};

// Always read the constraints :-).

// class Solution {
//     int res = Integer.MAX_VALUE;
    
//     public int distributeCookies(int[] cookies, int k) {
//         dfs(cookies, new int [k], 0, 0);
//         return res;
//     }
    
//     public void dfs(int [] cookies, int [] children, int idx, int max) {
//         if (idx >= cookies.length) {
//             res = Math.min(res, max);
//             return;
//         }
        
//         int c = cookies[idx];
//         for (int i = 0; i < children.length; i++) {
//             children[i] += c;
//             dfs(cookies, children, idx + 1, Math.max(max, children[i]));
//             children[i] -= c;
//         }
//     }
// }