class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // just simple binary search..
        int n=arr.size();
        // peak can never be at index 0 and n-1.. so start =1, end=n-2..
        int start=1, end=n-2;
        int ans;
        while(start<=end){

            int mid =start + (end-start)/2;

            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) // mid is peak element
              return mid;
            if(arr[mid]>arr[mid-1]){
               ans=mid; 
               start=mid+1;  // left side all small then mid.. so go right side
            }
            else
                end = mid-1;  // go left
            
        }
        return ans;
    
    }
};