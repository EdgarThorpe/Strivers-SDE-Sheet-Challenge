class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // int res = 0;
        // for(int i = 0; i < n; i++){
        //     int area = heights[i];
        //     for(int j = i-1; j >= 0; j--){
        //         if(heights[j]>=heights[i]) area+=heights[i];
        //         else break;
        //     }
        //     for(int j = i+1; j < n; j++){
        //         if(heights[j]>=heights[i]) area+=heights[i];
        //         else break;
        //     }
        //     res = max(res,area);
        // }
        // return res;


        //add area when popping
    stack <int> s;
    int res=0;
    int tp;
    int curr;
    
    for(int i=0;i<n;i++){
        while(s.empty()==false && heights[s.top()]>=heights[i]){
            tp=s.top();s.pop();
            curr=heights[tp]* (s.empty() ? i : i - s.top() - 1);
            res=max(res,curr);
        }
        s.push(i);
    }
    while(s.empty()==false){
        tp=s.top();s.pop();
        curr=heights[tp]* (s.empty() ? n : n - s.top() - 1);
        res=max(res,curr);
    }
    
    return res;


        
    }
};