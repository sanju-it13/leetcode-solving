class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0,j=0;
        int currSum=0;
        vector<int>minBestLen(n,INT_MAX); // use for overlapping check
        int bestMin=INT_MAX;
        int result=INT_MAX;
        // sliding window
        while(j<n){
          currSum+=arr[j];
          while(i<j && currSum > target){
            currSum-=arr[i];
            i++;
          }
          if(currSum==target){
            int len = j-i+1;
            if(i>0 && minBestLen[i-1] != INT_MAX)
             result=min(result,len+minBestLen[i-1]); // check that is there best length available at i-1..
            
            bestMin=min(bestMin,len);
          }
          minBestLen[j]=bestMin;
          j++;
        }
       return result == INT_MAX ? -1 : result;
    }
};