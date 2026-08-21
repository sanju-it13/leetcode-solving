class Solution {
public:

    long long findKthSmallest(vector<int>& coins, int k) {

        int n = coins.size();
        int totalMasks = 1 << n;

        long long hi =
            (long long)(*min_element(coins.begin(), coins.end())) * k;

        // lcm[mask] = LCM of coins represented by mask
        // If actual LCM > hi, store hi + 1
        vector<long long> lcm(totalMasks, 1);

        vector<int> sign(totalMasks);

        for (int mask = 1; mask < totalMasks; mask++) {

            int bit = __builtin_ctz(mask);
            int prev = mask & (mask - 1);

            long long g = gcd(lcm[prev], (long long)coins[bit]);

            // Prevent overflow and cap unnecessary LCMs
            if (lcm[prev] > hi / (coins[bit] / g)) {
                lcm[mask] = hi + 1;
            }
            else {
                lcm[mask] =
                    lcm[prev] / g * coins[bit];
            }

            // Odd number of coins -> add
            // Even number of coins -> subtract
            sign[mask] =
                (__builtin_popcount(mask) & 1) ? 1 : -1;
        }

        long long lo = 1;

        while (lo < hi) {

            long long mid = lo + (hi - lo) / 2;

            long long count = 0;

            for (int mask = 1; mask < totalMasks; mask++) {

                if (lcm[mask] > mid)
                    continue;

                if (sign[mask] == 1)
                    count += mid / lcm[mask];
                else
                    count -= mid / lcm[mask];
            }

            if (count >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};