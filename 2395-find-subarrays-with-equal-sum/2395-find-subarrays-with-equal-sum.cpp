class Solution {
public:
    bool findSubarrays(vector<int>& nums) {

        unordered_set<int>st;
        int n= nums.size();
        for(int i=0;i<n-1;i++){
           int sum = nums[i]+nums[i+1];
            
            if(st.count(sum))
             return true;  // equal sum sub array exist..

            st.insert(sum);

        } 

        return false;
    }
};