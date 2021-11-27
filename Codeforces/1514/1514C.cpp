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

ll power(ll a, ll n, int mod) {
    ll res = 1;
    while (n) {
        if (n%2) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

#define multi_test 0
void _main() {
    int n; cin >> n;
    int phi = 0;
    fto1 (i, 1, n) {
        phi += __gcd(n, i) == 1;
    }
    set<int> ans; ans.insert(1);
    vector<int> tmp;
    ll val = 1;
    fto1 (i, 2, n) {
        if (__gcd(i, n) == 1) {
            int x = power(i, phi-1, n);
            if (i != x) ans.insert(i), ans.insert(x);
            else tmp.push_back(i), val = val * i % n;
        }
    }
    if (val == 1) for (auto v: tmp) ans.insert(v);
    bug(sz(ans));
    for (auto v: ans) cout << v << ' ';
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