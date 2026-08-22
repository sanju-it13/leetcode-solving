class Solution {
public:
    bool checkDivisibility(int n) {
       
        int result1=0;
        int result2=1;
        int temp=n;

        while(temp){
            int digit = temp % 10;
            result1 += digit;
            result2 *= digit;
            temp/=10;
         }
    
     int result=result1+result2;

    if(n%result ==0)
        return true;
        
     return false;

    }
};