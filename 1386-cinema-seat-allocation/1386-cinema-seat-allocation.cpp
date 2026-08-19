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

        unordered_map<int,unordered_set<int>> x;
        // row no and seats in each row booked.

        for(auto& reserved : reservedSeats){   
         //reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
          int row =reserved[0];
          int seat =reserved[1];
           // insert it in map
           x[row].insert(seat);
           
        }
         int empty_seat= n-x.size();
        int result = empty_seat * 2;  // 2 group book for all empty row
          
        for(auto& [row , occupied_seat] : x){
               
          auto isAvailable=[&](int seat){
            return occupied_seat.find(seat) == occupied_seat.end();
          };

         bool GroupA= isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
         bool GroupB= isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
         bool GroupC= isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

         if(GroupA && GroupC)
           result+=2;
         else if(GroupA || GroupB || GroupC)
            result+=1;  

        }


        return result;

        
    }
};