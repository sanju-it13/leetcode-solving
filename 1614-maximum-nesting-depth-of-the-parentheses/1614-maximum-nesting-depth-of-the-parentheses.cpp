class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maximum=0;
        //stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                //st.push(count);
            }
            else if(s[i]==')'){
                maximum=max(maximum,count);
                count--;
            }
        }
        
     return maximum;
        
    }
};