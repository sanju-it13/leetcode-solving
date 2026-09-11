class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int totalnum=0;
        vector<int>digitCount(10,0); // count the number of digit (frequency)
        // firstposition(1 to 9) 2nd pos (0 to 9)  3rd pos (even 0,2,4,6,8)
        for(int x : digits){
            digitCount[x]++;
        }
        for(int i=1;i<=9;i++){ // first pos
            if(digitCount[i]==0) // not available
               continue;
            digitCount[i]--;  // available , pick it, freq reduce

            for(int j=0;j<=9;j++){
                if(digitCount[j]==0)
                   continue;
                digitCount[j]--;

                for(int k=0;k<=8;k=k+2){ 
                  if(digitCount[k]==0)
                   continue;
                   
                   totalnum++;
                }  
               digitCount[j]++;  
            }
            digitCount[i]++;
        }

       return totalnum;
    }
};