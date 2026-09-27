class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";

        for (char ch : s) {
            if (ch == '(') {
                st.push(current);
                current = "";
            } else if (ch == ')') {
                reverse(current.begin(), current.end());
                string previous = st.top();
                st.pop();
                current = previous + current;
            } else {
                current = current + ch;
            }
        }

        return current;
    }
};