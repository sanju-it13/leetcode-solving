class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>frequency;
        int result=0;
        // left -> left pointer, i -> right pointer
        int left=0;
        int bad=0;
     for(int i=0;i<n;i++){
        frequency[nums[i]] ++;
        if(frequency[nums[i]]==k+1)
         bad++;
        while(bad >0){ 
        
            frequency[nums[left]] --;

            if(frequency[nums[left]]==k)
              bad --;
          
          left++;
        }
        result = max(result , i-left+1);

     }
    
        return result;
    }
};