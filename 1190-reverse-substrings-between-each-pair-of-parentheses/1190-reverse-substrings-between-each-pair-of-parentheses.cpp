class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stack;
        string current = "";

        for (char ch : s) {
            if (ch == '(') {
                stack.push_back(current);
                current = "";
            } else if (ch == ')') {
                reverse(current.begin(), current.end());
                string previous = stack.back();
                stack.pop_back();
                current = previous + current;
            } else {
                current = current + ch;
            }
        }

        return current;
    }
};