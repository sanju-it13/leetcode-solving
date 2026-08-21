class Solution {
public:
    
    // A,B,C -> # coins.. we are calculating the corrected count removing duplicate multiples..
    /* coins{3,2,5}. and k=4.
                      3 -> 3,6,9,12
                      2 -> 2,4,6,8
                      5->  5,10,15,20
     start =1.. end =max(3,2,5) *k =5*4=20
     mid = 1+20 /2 =10;
     .. smallerCount(10,coins[3,2,5]);
      we are finding how many smallest number there before mid=10;
      2,3,4,5,6,6,8,9,[mid=10]
      //but we have to remove the duplicate.. (6). means Common part.. 
      
      for that we use inclusion exclusion principle. AUBUC = |A|+|B|+|C|-|A.B|-|A.C|-|B.C|+ |A.B.C|  
      for even order expression we substract (-|A.C|-|A.B|) 
      and for odd order expression we add  (|A|, +|B|,... +|A.B.C|).
      for 3 coins(A,B,C).. no of expression = 7.. 
      for n coins.. no. of expression = 2^n-1

   */

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
             //  mid/LCM -> how many duplicate present.
            
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
      long long End =(long long)(*min_element(coins.begin(),coins.end())) *k;
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