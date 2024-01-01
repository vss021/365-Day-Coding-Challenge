#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define pb push_back
#define si second
#define int long long
#define mod 1000000007
// #define mod 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define double long double
#define all(o) o.begin(),o.end()
using namespace std;

int power(int x, int y) {
    int res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y >>= 1; // y = y/2
        x = (x * x) % mod;
    }
    return res % mod;
}

int inv(int n) {
    return power(n, mod - 2) % mod;
}

int isprime(int n) {
    if (n < 2)
        return 0;
    int i;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return;
    }

    n--;
    int ans = 1;
    int rem = n - 1;
    ans += rem * (rem + 1);
    cout << ans << "\n";
}

int32_t main() {
    fast

    int t = 1;
    int tc = 0;
    cin >> t; 
    while (t--) {
        tc++;
        // cout << "Case #" << tc << ": ";
        solve();
    }
}
