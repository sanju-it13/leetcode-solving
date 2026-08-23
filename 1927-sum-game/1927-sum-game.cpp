class Solution {
public:
    bool sumGame(string num) {
        int L_Que_mark=0;
        int R_Que_mark=0;
        int L_Sum=0;
        int R_Sum=0;
        int n=num.length();
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2)
                  L_Que_mark ++;
                else
                 R_Que_mark++;  
            }
            else{
                if(i<n/2)
                 L_Sum+=num[i] - '0';
                else 
                  R_Sum+=num[i] -'0'; 
            }

        }

        int Total_Que_mark = L_Que_mark + R_Que_mark;

      // if total '?' is odd.. Alice always win.. because Alice start first and Alice has a last choice to create  not equal of both half.          
        if(Total_Que_mark % 2 != 0) 
        return true;  // Alice win

      // if Alice choose x .. then Bob will choose (k-x).. and k ->value will be 9.. if  k = 6.. and Alice choose 8.. Bob = 6 -8 =-2 that is not possible.. So if K=9.. then negative value not possible..

      // Now try to make a equation.. 
      /* 
          suppose there are 6 que mark.. left side 2, right side 4..
           (5?2?3)   (? ? ? 7 ?)
           now look any of side.. lets look in right side..
             ? ? ? 7 ? 
             Right = (Rightsum = 7) + (?+?+?+?)
             now for this ?+?+?+?
              if for first '?' Alice take 'x'.. then Bob will take for next '?'  9-'x'.. Similarly if Alice take 'y' then Bob will take 9-'y'.

              Right = Rightsum + (x + 9-x + y + 9-y)..
              Right = Rightsum + 18..
              For 4 '?' sum is 18.. then for 1'?' -> (18/4)=4.5
        
      Right = Rightsum + 4.5 * no of right side '?' mark
      similarly.. Left = Leftsum + 4.5 * no. of left side '?' mark

      */
      double Left = L_Sum + 4.5 * L_Que_mark;
      double Right = R_Sum + 4.5 * R_Que_mark;

      if(Left == Right)
        return false; // Bob win

     return true; //Alice win
    
    }
};