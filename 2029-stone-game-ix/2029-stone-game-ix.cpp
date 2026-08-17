class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int r0=0,r1=0,r2=0; //reminder 0,1,2

        for(int stone : stones){
            if(stone % 3 ==0)
             r0++;
            else if(stone % 3==1)
             r1++;
            else
              r2++;  
        }
       // pattern 1 A-> Alice, B->Bob
      // A B A B A B A B A .....
      // 1 1 2 1 2 1 2 1 2 ....

      // pattern 2 A-> Alice, B->Bob
      // A B A B A B A B A .....
      // 2 2 1 2 1 2 1 2 1 .....

     //even no. of reminder 0..
       if(r0 % 2==0) {
        return (r1>=1 && r2>=1) && (r2>=r1 || r1>=r2);
       }
       //odd no. of reminder 0..
       return abs(r1-r2)>=3;  
    }
};