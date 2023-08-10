class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>map;
        for(auto x : nums){
            map[x]++;
        }

        vector<int>ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minH;
        for(auto x : map){
            minH.push({x.second,x.first});
            if(minH.size()>k) minH.pop();
        }
        while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
        

        // unordered_map<int,int>map;
        // vector<int>ans;
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >minH;
        // for(auto x : nums){
        //     map[x]++;
        // }
        // for(auto x : map){
        //     minH.push({x.second,x.first});
        //     if(minH.size()>k){
        //         minH.pop();
        //     }
        // }
        // while(minH.size()>0){
        //     ans.push_back(minH.top().second);
        //     minH.pop();
        // }
        // return ans;
    }

    //     return result;
    // }
};