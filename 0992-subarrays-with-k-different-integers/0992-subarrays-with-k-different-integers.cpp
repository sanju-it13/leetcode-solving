class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int total;
        unordered_map<int,int>freq;
      
        // atleast k different integer
        int start=0,end=0,count=0; 
        int total1=0;
        while(end<n){
            freq[nums[end]]++; // add the freq of that number
            if(freq[nums[end]]==1)
              count++; // first time came
         while(count==k){
            total1+=n-end;
            freq[nums[start]]--;
            if(freq[nums[start]]==0)
              count--; 
            start++;
         }
          end++; // window increase until count
        }
        

        // atleast k+1 different integer
        start=0,end=0,count=0;
        freq.clear();
        k++;
        int total2=0;
        while(end<n){
            freq[nums[end]]++; // add the freq of that number
            if(freq[nums[end]]==1)
              count++; // first time came
         while(count==k){
            total2+=n-end;
            freq[nums[start]]--;
            if(freq[nums[start]]==0)
              count--; 
            start++;
         }
          end++; // window increase until count
        }
 // exactly k different integer = atleast k diff int - atleast k+1 diff int.
        total=total1-total2;
        return total;
    }
};