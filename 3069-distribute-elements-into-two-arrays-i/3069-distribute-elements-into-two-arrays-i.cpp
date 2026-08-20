class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        //vector<int>result;
         arr1.push_back(nums[0]);
         arr2.push_back(nums[1]);
        int j=0,k=0;
        for(int i=2;i<nums.size();i++){
            
            if(arr1.back()>arr2.back()){
               
                arr1.push_back(nums[i]);
            }
            else{
                
                arr2.push_back(nums[i]);
            }
        }
       //for(int x : arr2)
         //arr1.push_back(x);
     arr1.insert(arr1.end(),arr2.begin(),arr2.end());
       // for(int x : arr2)
        // result.push_back(x);

     //return result;
     return arr1;
    }
};