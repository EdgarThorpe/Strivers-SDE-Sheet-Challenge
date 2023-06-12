class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;
        int minprice = INT_MAX;
        int maxprofit = 0;

        for(int i = 0; i < n; i++){
            
            if(prices[i]<minprice){
                minprice=prices[i];
            }
            else if(prices[i]-minprice>maxprofit){
                maxprofit=prices[i]-minprice;
            }

        }
        cout<<maxprofit<<" "<<minprice;
        // if(maxprofit==0){
        //     return 0;
        // }
        // else res = maxprofit-minprice;
        return maxprofit;
        
    }
};