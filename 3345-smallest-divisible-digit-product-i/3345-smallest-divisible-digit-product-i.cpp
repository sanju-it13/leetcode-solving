class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while (true){
        int k = n;
        int ans = 1;
        while(k) {
            ans *= (k% 10);
             k = k/10;
        }

        if ( ans % t == 0)
          return n;
        
        n++;
     }
    }  
};