class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini=INT_MAX, min_index=-1;
        int maxi=INT_MIN, max_index=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<mini){
              mini=nums[i];
              min_index=i;
            }
            if(nums[i]>maxi){
              maxi=nums[i];
              max_index=i;
            }
        }
      // both delete from front
       int front_front=max(min_index,max_index)+1;
       //both delete from back
       int back_back=n-min(min_index,max_index);

       // min from front, max from back
        int front_back=(min_index+1) + (n-max_index);
        // max from front . min from back
        int back_front=(max_index+1) + (n-min_index);

        return min({front_front,back_back,front_back,back_front});

    }

};