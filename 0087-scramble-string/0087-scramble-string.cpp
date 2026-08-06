class Solution {
public:
    
    bool answer(string s1, string s2, unordered_map<string,bool>&dp){
        int n = s1.size();
        if (s1 == s2)  return true;
        vector<int>frequency(26,0);

        for(int i=0;i<n;i++){
            frequency[s1[i]-'a'] ++;
            frequency[s2[i]-'a'] --;

        }

        for(int i : frequency){
            if(i)
              return false;
        }

        string key = s1+s2;

        if(dp.find(key) != dp.end())
           return dp[key];

        for(int i=1;i<n;i++){

            bool noSwap = answer(s1.substr(0,i), s2.substr(0,i),dp) &&
                          answer(s1.substr(i), s2.substr(i),dp);
         

        if(noSwap)
          return dp[key]=true;

        bool Swap = answer(s1.substr(0,i), s2.substr(n-i),dp) &&
                          answer(s1.substr(i), s2.substr(0,n-i),dp);  

        if(Swap)
           return dp[key] = true;                  
        }

        return dp[key]=false;

    }


    bool isScramble(string s1, string s2) {

        unordered_map<string,bool>dp;

        return answer(s1,s2,dp);
        
    }
};