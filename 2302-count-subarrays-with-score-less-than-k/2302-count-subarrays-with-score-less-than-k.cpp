class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int start=0,end=0;
        long long count=0;
        long long sum=0;
        long long proSum=0;
        while(end<nums.size()){
            sum+=nums[end];
            long long length=end-start+1;
            proSum=sum*length;

            while(proSum >= k && start<=end){
                sum-=nums[start];
                start++;
                length--;
                proSum=sum*length;
            }
            
           count+=length;
            end++;
        }
       return count; 
    }
};