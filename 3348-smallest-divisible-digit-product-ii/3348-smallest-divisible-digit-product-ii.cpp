#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Subtracts prime factors of digit d from (c2, c3, c5, c7)
    void remove_factors(int d, int &c2, int &c3, int &c5, int &c7) {
        if (d <= 0) return;
        while (d % 2 == 0) { c2--; d /= 2; }
        while (d % 3 == 0) { c3--; d /= 3; }
        while (d % 5 == 0) { c5--; d /= 5; }
        while (d % 7 == 0) { c7--; d /= 7; }
    }

    // Adds back prime factors of digit d to (c2, c3, c5, c7)
    void add_factors(int d, int &c2, int &c3, int &c5, int &c7) {
        if (d <= 0) return;
        while (d % 2 == 0) { c2++; d /= 2; }
        while (d % 3 == 0) { c3++; d /= 3; }
        while (d % 5 == 0) { c5++; d /= 5; }
        while (d % 7 == 0) { c7++; d /= 7; }
    }

    // Converts needed factor counts into the shortest sorted digit string
    string get_digits(int c2, int c3, int c5, int c7) {
        c2 = max(0, c2); c3 = max(0, c3); c5 = max(0, c5); c7 = max(0, c7);
        string s = "";
        s.append(c7, '7');
        s.append(c5, '5');
        s.append(c3 / 2, '9'); c3 %= 2;
        s.append(c2 / 3, '8'); c2 %= 3;

        if (c3 == 1 && c2 == 1)      { s += '6'; }
        else if (c3 == 1 && c2 == 2) { s += "26"; }
        else if (c3 == 1)            { s += '3'; }
        else if (c2 == 2)            { s += '4'; }
        else if (c2 == 1)            { s += '2'; }

        sort(s.begin(), s.end());
        return s;
    }

public:
    string smallestNumber(string num, long long t) {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        while (t % 2 == 0) { c2++; t /= 2; }
        while (t % 3 == 0) { c3++; t /= 3; }
        while (t % 5 == 0) { c5++; t /= 5; }
        while (t % 7 == 0) { c7++; t /= 7; }
        if (t > 1) return "-1"; // Invalid prime factor outside 2, 3, 5, 7

        int N = num.length();
        int first_zero = num.find('0');
        if (first_zero == string::npos) first_zero = N;

        // 1. Check if num itself works (if zero-free)
        if (first_zero == N) {
            int r2 = c2, r3 = c3, r5 = c5, r7 = c7;
            for (char ch : num) remove_factors(ch - '0', r2, r3, r5, r7);
            if (r2 <= 0 && r3 <= 0 && r5 <= 0 && r7 <= 0) return num;
        }

        // 2. Pre-calculate factors needed after prefix 0..max_i-1
        int max_i = min(N - 1, first_zero);
        int r2 = c2, r3 = c3, r5 = c5, r7 = c7;
        for (int j = 0; j < max_i; j++) {
            remove_factors(num[j] - '0', r2, r3, r5, r7);
        }

        // 3. Try matching a prefix ending at index i
        for (int i = max_i; i >= 0; i--) {
            int start_digit = (i == first_zero) ? 1 : (num[i] - '0' + 1);
            for (int d = start_digit; d <= 9; d++) {
                int tr2 = r2, tr3 = r3, tr5 = r5, tr7 = r7;
                remove_factors(d, tr2, tr3, tr5, tr7);

                string min_s = get_digits(tr2, tr3, tr5, tr7);
                int rem_len = N - 1 - i;

                if ((int)min_s.length() <= rem_len) {
                    string padding(rem_len - min_s.length(), '1');
                    return num.substr(0, i) + to_string(d) + padding + min_s;
                }
            }

            // Step backward: add back the factors of num[i - 1] for position i - 1
            if (i > 0) {
                add_factors(num[i - 1] - '0', r2, r3, r5, r7);
            }
        }

        // 4. Fallback: Greater length required (N+1 or minimum needed length)
        string min_s = get_digits(c2, c3, c5, c7);
        int target_len = max(N + 1, (int)min_s.length());
        string padding(target_len - min_s.length(), '1');
        return padding + min_s;
    }
};