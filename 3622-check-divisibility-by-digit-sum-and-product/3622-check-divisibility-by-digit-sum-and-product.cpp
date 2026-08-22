class Solution {
public:
    bool checkDivisibility(int n) {
       
        int result1=0;
        int result2=1;
        int temp=n;
        int temp2=n;

        while(temp){
            result1 += temp%10;
            temp/=10;
         }
        while(temp2){
            result2 *= temp2 % 10;
            temp2 /= 10;
          }  

     int result=result1+result2;

    if(n%result ==0)
        return true;
        
     return false;

    }
};