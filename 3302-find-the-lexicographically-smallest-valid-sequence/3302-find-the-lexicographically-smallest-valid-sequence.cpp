class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

      vector<int>right(m,-1);

         // matching from right

        for(int i=n-1, j= m-1 ; i>=0 && j>=0; i--){

            if(word1[i] == word2[j]){
              right[j--]=i;
              
            }
        }

        vector<int>answer(m);
        bool flag = true; 
      // can we change the char in mismatch position ? (only 1 change possible) true -> yes.. false -> no..
      int j =0;
      for(int i=0; i<n && j<m ; i++){
        if(word1[i]==word2[j]){
             answer[j++]=i;
             
        }
        else if(flag && (j==m-1 || i<right[j+1])){
            // if i =2.. then the value store in right[] must be after index 2.. otherwise not strictly increasing or lexicographically order like 1,2,3,4...
             
             answer[j++]=i;
             
             flag = false;
        }

        if(j==m) return answer;
       
      }

         return {};
    }
    };