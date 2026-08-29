class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // total no of bananas..
        long long sum=0; 
        int end=0; 
        int ans;
        for(int i=0;i<piles.size();i++){
             sum+=piles[i];
            end=max(end,piles[i]); // maximum no. of bananas
        }
        //int start= sum/h;  // minimum banana can eat in hour.
        int start =1;
        // [3,6,7,11] -> hour=8,  27/8 =3.. minimum 3 banana must eat to complete all.
        // so start=3... and maximux 11 bananna can eat in hour.. end=11
      while(start<=end){
        int mid=start+(end-start)/2; // mid=3+11/2=7..

        //now check if koko eat 7 bananas/hour.. total time take how much..
        long long total_time=0;
        for(int i=0;i<piles.size();i++){
            total_time+=piles[i]/mid;
            if(piles[i]%mid !=0)
             total_time++;
          /* mid=4, piles[i]=8.. then totaltime=8/4=2.. and 8%4=0 .. if(piles[i]%mid) become false.. now if mid=4, piles[i]=7.. then totaltime = 7/4=1
         and 7%4=3.. if(piles[i]%mid) become true.. so totaltime ++..
          then total time =2 for mid=4, piles[i]=7.  */
        }
        if(total_time<=h){
          ans=mid;  // possible answer..
          end=mid-1;  // go left
        }
        else{  // total_time > hour .. then mid ka value increse karna haii..
            start=mid+1; // go right
        }
      }
      return ans;

    }
};