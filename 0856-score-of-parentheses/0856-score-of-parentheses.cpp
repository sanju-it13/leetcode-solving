class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0;
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
               st.push(score);
               score=0;
            }
            else{ 
                if(s[i-1]=='('){  // simple -> ()
                   score= st.top()+1;
                }
                else{
                    // nested ((()))
                    score=st.top()+ (2*score);
                }
                st.pop();
            }   
        }
       return score; 
    }
};