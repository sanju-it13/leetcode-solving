class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = nums.size();

for (int i = 0; i < nums.size(); i++) {
    x ^= i; // xor with expected number
    x ^= nums[i]; // xor with actual number
}
        

       return x; 
    }
    
};