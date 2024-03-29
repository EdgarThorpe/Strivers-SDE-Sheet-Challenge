class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		// unordered_set<char> set;
    
		// int i = 0, j = 0, n = s.size(), ans = 0;
    
		// while( i<n && j<n)
		// {
		// 	if(set.find(s[j]) == set.end()) //If the character does not in the set
		// 	{
		// 		set.insert(s[j++]); //Insert the character in set and update the j counter
		// 		ans = max(ans, j-i); //Check if the new distance is longer than the current answer
		// 	}
		// 	else
		// 	{
		// 		set.erase(s[i++]); 
		// 		/*If character does exist in the set, ie. it is a repeated character, 
		// 		we update the left side counter i, and continue with the checking for substring. */
		// 	}
		// }
    
		// return ans;

		int ans = 0;
		int i = 0, j = 0;
		int n = s.length();
		if(n==0) return 0;
		unordered_set<char>set;
		while(i < n && j < n){
			if(set.find(s[j])==set.end()){
				set.insert(s[j]);
				ans = max(ans, j-i);
				j++;
			}
			else{
				set.erase(s[i]);
				i++;
			}
			
		}
		return ans+1;
	}
};