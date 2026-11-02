class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        nth_element(begin(nums),begin(nums)+n/2,end(nums));
        int mid=nums[n/2];
        int res=0;
        for(int i=0;i<n/2;i++){
           res+=abs(nums[i]-mid);  //left side
           res+=abs(nums[n-i-1]-mid);
        }
        return res;
        
    }
};