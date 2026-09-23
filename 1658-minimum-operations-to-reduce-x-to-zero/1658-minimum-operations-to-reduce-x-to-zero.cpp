class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int target = total - x;
        if (target==0) return nums.size();
        if(target<0) return -1;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prefixsum=0;
        int maxLen=-1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int required = prefixsum-target;

            if(mp.find(required) != mp.end())
                maxLen=max(maxLen, i-mp[required]);
            
            if(mp.find(prefixsum)==mp.end())
               mp[prefixsum]=i;
        }

        if(maxLen==-1) return -1;

        return nums.size()-maxLen;
        
    }
};