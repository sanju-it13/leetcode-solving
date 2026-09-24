class Solution {
public:
    string minWindow(string s, string t) {
        int total=t.size();
        vector<int>mp(256,0);
        for(int i=0;i<t.size();i++)
          mp[t[i]]++;

        int start=0,end=0,ans=INT_MAX,index=-1;

        while(end<s.size()){

            mp[s[end]]--; // decrease the count of char..

            if(mp[s[end]]>=0)
             total --; 

            while(!total && start<=end){
              //  get the string
              if(ans > end-start+1){
                ans=end-start+1;
                index=start;
              }
              // decrease the window
              mp[s[start]]++; // map update
              if(mp[s[start]]>0)
                total++;

              start++; 
            }
            // window increase..
            end++; 
        } 
        if(index==-1) return "";

        string str=""; 
        for(int i=index;i<index+ans;i++){
            str+=s[i];
        }
        return str;
    }
};