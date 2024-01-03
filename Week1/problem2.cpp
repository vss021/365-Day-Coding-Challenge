
#include <bits/stdc++.h>
using namespace std;

// clang-format off
// <----------------------- Macros Start Here ----------------------->

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define el   '\n'
#define MOD1 1000000007
#define MOD2 998244353
#define INF numeric_limits<ll>::max()

// Container Macros
#define all(x)      x.begin(), x.end() // sort(all(name))
#define rall(x)     x.rbegin(), x.rend() 
#define popFront(x) x.erase(x.begin())
#define mp(x, y)    make_pair(x, y)
#define pb          push_back
#define ppb         pop_back
#define ff          first
#define ss          second

// Typedefs Here
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector <ll> vl;
typedef vector <pair <ll, ll> > vll;
typedef pair <ll, ll> pll;

// <----------------------- Macros End Here ----------------------->


// <----------------------- Predefined Goodies/Mac Start Here ----------------------->

ll GCD(ll a, ll b) {if (b > a) {return GCD(b, a);} if (b == 0) {return a;} return GCD(b, a % b);}
ll LCM(ll a, ll b) { return (a / GCD(a, b)) * b; }
ll pwr(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return pwr(a, b - 2, b);}
ll modAdd(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll modMul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll modSub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll modDiv(ll a, ll b, ll m) {a = a % m; b = b % m; return (modMul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
bool isPrime(ll n) { if(n < 2) return false; for(ll k = 2; k * k <= n; k++) if(n % k == 0) return false; return true; }

// <----------------------- Predefined Goodies/Mac End Here ----------------------->




void solve() {
    int n;
    cin >> n;

    vector<int> A_array(n), B_array(n);

    for (int i = 0; i < n; ++i) {
        cin >> A_array[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> B_array[i];
    }

    sort(A_array.begin(), A_array.end());
    sort(B_array.begin(), B_array.end());

    int size = n-1;

    int sum = A_array[0] + B_array[size];
    
    bool is = false;

    for(int i = 0; i <= size; i++) {
        
        int currSum = A_array[i] + B_array[size - i];

        if(currSum != sum) {
           is = true;
           break;
        }
    }

    if(is){
        cout << -1 << endl;
    }
    else{
        
    for(int i = 0; i <= size; i++) {
        cout << A_array[i] << " ";
    }
    cout << endl;

    for(int i = 0; i <= size; i++) {
        cout << B_array[size-i] << " ";
    }
    cout << endl;
    
    }
    
}

int main() {
    
    int TC_V;
    cin>> TC_V;

    while(TC_V--)
    {

        solve();
    
    }

    
	return 0;
}
