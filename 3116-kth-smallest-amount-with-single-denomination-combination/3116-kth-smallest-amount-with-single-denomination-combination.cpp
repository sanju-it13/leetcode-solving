class Solution {
public:
    long long smallerCount(long long mid, vector<int>& coins){
        long long Correctedcount=0;
        int n =coins.size();

        for(int expression =1; expression <= pow(2,n)-1; expression++){
            long long LCM =0;
            long long order =0;  // even or odd order of expression

            for(int i=0; i<n;i++){
                if(expression & (1<<i)){
                    order ++;

                  if(LCM ==0)
                     LCM = coins[i];
                  else{
                    LCM = LCM * coins[i] / gcd(LCM,coins[i]);
                    // LCM(a,b)= a*b / gcd(a,b)
                  }     
                }
            }

            if(order % 2==0){
                Correctedcount -= mid/LCM;

            }
            else{
                Correctedcount+= mid/LCM;
            }

        }

        return Correctedcount;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long result=-1;
        long long start=1;
      long long End= (long long)(*max_element(begin(coins),end(coins)))*k;
        // coins(3,2,5) -> max = 5.. end = k times multiples of 5 .
        // then apply binary search
        while(start <= End){
            long long mid = start + (End-start)/2;

            if(smallerCount(mid, coins) >=k){ // we can find kth smallest in left side

              result = mid;  // store mid .. may be it is the kth smallest. 
              End = mid-1;   // if not .. then do binary search again with new END.

            }
            else{
                start = mid+1;
            }
        }
        return result;
    }
};