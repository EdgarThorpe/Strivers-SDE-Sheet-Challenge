class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;

        // for(int i = 1; i < n-1; i++){
        //     int leftMax = height[i];
        //     for(int j = 0; j < i; j++){
        //         leftMax = max(leftMax,height[j]);
        //     }
        //     int rightMax = height[i];
        //     for(int j = i+1; j < n; j++){
        //         rightMax = max(rightMax,height[j]);
        //     }
            // res+=(min(leftMax,rightMax)-height[i]);
        // }
        // return res;

        //compute lMax and rMax arrays before hand to decrease TC
        int lmax[n], rmax[n];
        lmax[0]=height[0];
        for(int i=1; i<n; i++){
            lmax[i]=max(height[i],lmax[i-1]);
        }
        rmax[n-1]=height[n-1];
        for(int i=n-2; i>0; i--){
            rmax[i]=max(height[i],rmax[i+1]);
        }
        for(int i = 1; i<n-1; i++){
            res = res + (min(rmax[i],lmax[i])-height[i]);
        }

        return res;

    }

};