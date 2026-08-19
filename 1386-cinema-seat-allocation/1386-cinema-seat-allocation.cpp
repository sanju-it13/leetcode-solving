class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        /* Group A -> seats 2, 3, 4, 5
           Group B -> seats 4, 5, 6, 7
           Group C -> seats 6, 7, 8, 9

          ->  we can book maximum 2 group in a row (only Group A, C) 
           beacause no redundent seat in group A,C..
          -> if a row has no occupied seat then for this row .. we will book 2 group seat(A,C)
          -> otherwise we will check each group with occupied seat. */

        unordered_map<int,int> x;
        // row no and seats in each row booked.

        for(auto& reserved : reservedSeats){   
         //reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
          int row =reserved[0];
          int seat =reserved[1];
    // doing OR operation and left shift.. [1,2],[1,8] -> 0010000010
           x[row] = (x[row] | (1 << seat));   
        }
         int empty_seat= n-x.size();
        int result = empty_seat * 2;  // 2 group book for all empty row

         // Group A {2,3,4,5} -> 0000011110
         // Group B {4,5,6,7} -> 0001111000
         // Group C {6,7,8,9} -> 0111100000

         int maskA=(1<<2)|(1<<3)|(1<<4)|(1<<5);
         int maskB=(1<<4)|(1<<5)|(1<<6)|(1<<7);
         int maskC=(1<<6)|(1<<7)|(1<<8)|(1<<9); 

        for(auto& [row , occupied_seat] : x){
               

         bool GroupA= (occupied_seat & maskA) ==0;
         bool GroupB= (occupied_seat & maskB) ==0;
         bool GroupC= (occupied_seat & maskC) ==0;

         if(GroupA && GroupC)
           result+=2;
         else if(GroupA || GroupB || GroupC)
            result+=1;  

        }


        return result;

        
    }
};