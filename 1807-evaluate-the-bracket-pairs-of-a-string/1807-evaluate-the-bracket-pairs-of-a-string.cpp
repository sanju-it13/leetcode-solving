class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto & x:knowledge)
           mp[x[0]]=x[1];

        int n=s.size();
        int i=0;
        string result;
        while(i<n){
          if(s[i]=='('){
            i++;
            string key;
            while(s[i]!=')' && i<n){
                key+=s[i];
                i++;
             }
             //c++ 20 
           result+=mp.contains(key) ? mp.at(key) : "?";
          }
          else
            result+=s[i];
          
            i++;
        }   
     return result;
        
    }
};