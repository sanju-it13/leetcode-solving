class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth=0,score=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')
               depth++;
            else{
                depth --;
                if(s[i-1]=='('){
                   score+=(1<<depth);  // ((())) -> 2^2=4
                }
            }   
        }
       return score; 
    }
};