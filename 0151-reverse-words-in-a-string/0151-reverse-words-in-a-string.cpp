class Solution {
public:

// string reverse(string &s, int low, int high){
//     while(low<=high){
//         swap(s[low],s[high]);
//         low++;
//         high--;
//     }
//     return s;
// }


string reverseWords(string s) {


//     while(s[0] == ' ') s.erase(0, 1); //Remove spaces from the beginning
//     while(s[s.size()-1]==' ') s.erase(s.size()-1); //Remove spaces from the ending
//     if(s.size() == 0) return s;
    stack<string> stack;
    string result;
    for(int i=0; i<s.size(); i++) {
        string word;
        if(s[i]==' ') continue; //skip spaces
        while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
            word += s[i]; i++;
        }
        stack.push(word); //push word to the stack
    }
    while(!stack.empty()) {
        result += stack.top(); stack.pop();
        if(!stack.empty()) result += " ";
    }
    return result;



    // int start = 0, n = s.size();
    // for(int end = 0; end < n; end++){
    //     if(s[end]==' '){
    //         reverse(s,start,end-1);
    //         start = end+1;
    //     }
    // }

    // reverse(s,start,n-1);
    // reverse(s,0,n-1);

    // return s;
    }



    
};