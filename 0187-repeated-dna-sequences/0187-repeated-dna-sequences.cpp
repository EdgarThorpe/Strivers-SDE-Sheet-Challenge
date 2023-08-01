class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string>ans;
        unordered_map<string,int>mp;
        for(int i = 0; i < n; i++){
            mp[s.substr(i,10)]++;
        }
        for(auto x : mp){
            if(x.second>1){
                ans.push_back(x.first);
            }
        }
        return ans;
        
    }
};