class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char ch : s) {
           if(ch == ')'){
            string temp="";
            // pop character until '('
            while(!st.empty() && st.top() !='('){
                temp+=st.top();
                st.pop();
             }
              // after that remove '(' this from stack
              if(!st.empty())
                st.pop();
              for(char c : temp)
                st.push(c);  
           }
           else{
            st.push(ch);
           }
        }

        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};