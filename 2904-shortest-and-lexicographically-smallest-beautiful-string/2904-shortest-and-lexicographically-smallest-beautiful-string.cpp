class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // using Sliding window..

    int i=0,j=0;
    string ans="";
    int n=s.length();
    int count=0; // 1's count
   while(j<n){
    
    if(s[j]=='1')
      count ++;
      
    // window Shrinking .. when count > k.. then  i++   
     while(count>k || s[i]=='0'){
      
      if(s[i]=='1') count--;

      i++;

     }

    if(count == k){
        int len = j-i+1;
        string temp =s.substr(i,len); // window create
     if(ans.empty() || ans.length()>len || (temp.length()==ans.length() && temp < ans) )
        ans=temp;   
    }  
    
      j++;
   }

     return ans;   
    }
};