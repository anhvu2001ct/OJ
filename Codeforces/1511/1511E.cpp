#ifdef _LOCAL
    #include "local_include.hpp"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(it, a) for (auto it = (a).begin(); it != (a).end(); ++it)

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define bc __builtin_popcountll
#define endl '\n'
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define buga(a, s, e) fto(__i, s, e) cout << a[__i] << " \n"[__i == e];
#define bugar(a, s, e) cout << '{'; if (e < s) cout << '}'; else fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

template<typename T>
void bug(T const &var) { cout << var << endl; }

template<typename T, typename... Args>
void bug(T const &var, Args const &... args) {
    cout << var << ' ';
    bug(args...);
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e5+5;

int const mod = 998244353;
int n, m, total;
vector<string> a;

ll power(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n%2) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll calc(int n, int m, vector<string> const &a) {
    vector<vector<ll>> dp(n);
    ll res = 0;
    fto1 (i, 0, n) {
        dp[i].resize(m);
        fto1 (j, 0, m-1) {
            if (a[i][j] == '*' || a[i][j+1] == '*') dp[i][j] = 0;
            else if (j == 0 || a[i][j-1] == '*') dp[i][j] = power(2, total-2, mod);
            else if (j == 1 || a[i][j-2] == '*') dp[i][j] = power(2, total-3, mod);
            else dp[i][j] = (dp[i][j-2] * power(4, mod-2, mod) + power(2, total-3, mod)) % mod;
            res += dp[i][j];
            res %= mod;
        }
    }
    return res;
}

vector<string> rev_matrix(int n, int m, vector<string> const &a) {
    vector<string> res(m);
    fto1 (i, 0, m) {
        fto1 (j, 0, n) res[i] += a[j][i];
    }
    return res;
}

#define multi_test 0
void _main() {
    cin >> n >> m;
    a.resize(n);
    fto1 (i, 0, n) {
        cin >> a[i];
        fto1 (j, 0, m) total += (a[i][j] == 'o');
    }
    bug((calc(n, m, a) + calc(m, n, rev_matrix(n, m, a))) % mod);
}

int main() {
    #ifdef _LOCAL
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t = 1; if (multi_test) cin >> t;
    while (t--) _main();

    #ifdef _LOCAL
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}