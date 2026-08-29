class Solution {
public:
    void rotate(vector<int>& nums, int k) {

      int n=nums.size();
        k = k%n; // where k >=n;
       // reverse the whole array
       reverse(nums.begin(),nums.end());

       // reverse the first k element
       reverse(nums.begin(),nums.begin()+k);

       // reverse remaining element
       reverse(nums.begin()+k,nums.end());
    }
};