class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long lower = 1000;
        long long commas = 1;

        while (lower <= n) {
            long long upper = min(n, lower * 1000 - 1);

            ans += (upper - lower + 1) * commas;

            lower *= 1000;
            commas++;
        }

        return ans;
    }
};