class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        for (auto [x, count] : freq) {
            if (count % 2 != 0)
                return false;
        }

        return true;
    }
};