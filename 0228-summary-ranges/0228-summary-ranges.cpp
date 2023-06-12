class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==1)
        {
            return {to_string(nums[0])};
        }
        else if(nums.size()==0)
        {
            
            return ans;
        }
        deque<int> dq;
        dq.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] == dq.back()+1)
            {
                dq.push_back(nums[i]);
            }
            else
            {
                string temp = "";
                temp+=to_string(dq.front());
                if(dq.size()==1)
                {
                    ans.push_back(temp);
                }
                else
                {
                    temp+="->";
                    temp+=to_string(dq.back());
                    ans.push_back(temp);   
                }
                while(!dq.empty())
                {
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
        }
        if(!dq.empty())
        {
            cout<<dq.front()<<" "<<dq.back()<<endl;
            string temp = "";
            temp+=to_string(dq.front());
            if(dq.size()==1)
            {
                ans.push_back(temp);
            }
            else
            {
                temp+="->";
                temp+=to_string(dq.back());
                ans.push_back(temp);   
            }
        }
        
        return ans;
    }
};