class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int total=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
           if(mp.count(sum-k)){
                total+=mp[sum-k];
                mp[sum]++;
            }
            else{
               mp[sum]++;
            }
        }
        return total;
    }
};