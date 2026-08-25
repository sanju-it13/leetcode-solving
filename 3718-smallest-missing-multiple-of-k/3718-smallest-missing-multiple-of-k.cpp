class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool>mark(101);
        for(int &i : nums){
            mark[i]=1;
        }
        int x =k;
     while(x<101){
        if(mark[x]==0)
         return x;

        x+=k; 
     }
     return x;
    }
};