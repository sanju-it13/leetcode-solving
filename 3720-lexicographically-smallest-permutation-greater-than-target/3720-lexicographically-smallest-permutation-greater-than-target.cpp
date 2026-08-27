class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> count(26, 0);

        for (char c : s)
            count[c - 'a']++;

        int n = s.size();

        // Match target from left to right as much as possible
        int i = 0;

        while (i < n && count[target[i] - 'a'] > 0) {
            count[target[i] - 'a']--;
            i++;
        }

        // Now move backward and try to make the answer greater
        while (i >= 0) {

            // If we couldn't match target[i], we start from here.
            if (i < n) {

                // Find smallest available character > target[i]
                for (int c = target[i] - 'a' + 1; c < 26; c++) {

                    if (count[c] == 0)
                        continue;

                    string ans = target.substr(0, i);

                    ans.push_back('a' + c);

                    count[c]--;

                    // Fill remaining positions with smallest chars
                    for (int j = 0; j < 26; j++) {
                        while (count[j] > 0) {
                            ans.push_back('a' + j);
                            count[j]--;
                        }
                    }

                    return ans;
                }
            }

            // Move one position left.
            // Restore target[i-1] because it is no longer
            // part of the fixed prefix.
            if (i == 0)
                break;

            i--;

            count[target[i] - 'a']++;
        }

        return "";
    }
};