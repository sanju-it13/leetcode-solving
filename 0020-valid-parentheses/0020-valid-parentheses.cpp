class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        if (s.size() % 2 != 0) return 0;

        for(char ch: s){
            if(ch=='(' || ch=='{' || ch =='['){
                st.push(ch);
            }
            else{
                if(st.empty())
                  return 0;
                else if(ch == ')'){
                    if(st.top() != '(')
                      return 0;
                    else
                       st.pop();  
                }
                 else if(ch == '}'){
                    if(st.top() != '{')
                      return 0;
                    else
                       st.pop();  
                 }
               else{
                    if(st.top() != '[')
                      return 0;
                    else
                       st.pop();  
                }
            }
        }
        return st.empty();
    }
};