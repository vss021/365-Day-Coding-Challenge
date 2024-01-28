#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    
public:
    long long nCr(long long n, long long r) {
        if (n < r)
            return 0;

        long long res = 1;

        for (int i = 1; i <= r; ++i)
            res = res * (n - r + i) / i;

        return res;
    }

    long long reachLast(int bit, int k) {
        long long res = 1;

        for (int i = 1; i < k; ++i)
            res += nCr(bit, i);

        return res;
    }

    long long rep(long long n, int k, int bit) {
        long long res = static_cast<long long>(1) << bit;

        if (n == 1)
            return res;

        for (int cur = bit - 1; cur > 0; --cur) {

            long long nextOnes = 1;

            for (int i = cur - 1; i >= 0; --i)
                nextOnes += reachLast(i, k);

            if (nextOnes >= n)
                continue;

            --k;
            res |= (static_cast<long long>(1) << cur);
            n -= nextOnes;

            if (n == 1)
                return res;
        }

        if (n == 2)
            res |= 1;

        return res;
    }

    long long findNthNumber(int n, int k) {
        if (--n == 0)
            return 0;

        for (int i = 0; i <= 63; ++i) {

            long long res = reachLast(i, k);

            if (n <= res)
                return rep(n, k - 1, i);

            n -= res;
        }

        return 0;
    }
};

int main() {
    Solution solution;

    int n = 5;
    int k = 3;

    long long result = solution.findNthNumber(n, k);

    cout << "The " << n << "th number with k bits set is: " << result << endl;

    return 0;
}
