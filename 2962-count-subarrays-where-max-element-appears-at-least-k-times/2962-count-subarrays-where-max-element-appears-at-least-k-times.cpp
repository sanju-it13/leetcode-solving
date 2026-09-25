class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
     int n=nums.size();
    // find max element
    int maxElement=INT_MIN;
    for(int i=0;i<n;i++)
     maxElement=max(maxElement,nums[i]);
   
   int start=0,end=0,count=0;
   long long total=0;
   while(end<n){
    if(nums[end]==maxElement)
      count++;
    while(count==k){
        total+=n-end; // no of subarray
     if(nums[start]==maxElement)
       count--;
     start++; 
    }

    end++;  
   }

  return total;
        
    }
};