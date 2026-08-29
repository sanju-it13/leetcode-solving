class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>arr;
        int n = nums.size();

        for (int first = 0; first < n; first++) {
            int second = target - nums[first]; 
            if (arr.count(second)) {
                return {arr[second], first}; // try to find second is available or not
            }
            arr[nums[first]] = first; // add the current no and its index to hash map
        }

        return {};
    }
};