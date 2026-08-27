class Solution {
public:
  string result ="";
  bool solve(string &curr, vector<int>&count,string &target,int i, bool greater){
        //base case
    if(i == target.length()){
         if(greater==true){
            result = curr;
            return true;
         }
         return false;  
    }
   for(char j ='a'; j<='z';j++){
       if(count[j-'a']==0)
         continue;
       if(greater == false && j<target[i])
          continue;


      curr.push_back(j);
      count[j-'a']--;

        bool isgreater=greater || j > target[i];

        if(solve(curr,count,target,i+1,isgreater)){
            return true;
        } 
        //undo
        curr.pop_back();
        count[j-'a']++;   
   }
    return false;

  }
    string lexGreaterPermutation(string s, string target) {
        vector<int>count(26,0);
        for(char &i : s)
          count[i -'a']++;
        
        string curr;
        solve(curr,count,target,0,false);
        return result;
    }
};