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
#define fat(i, a) for (auto i : (a))

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define bc __builtin_popcountll
#define y1 ansdj
#define endl '\n'
#define ff first
#define ss second
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define buga(a, s, e) cout << '{'; if (e < s) cout << '}'; else fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

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
int const maxn = 1e5+3;

int n;
int a[maxn], cnt[maxn], need[maxn];
ll fac[maxn];

ll power(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n%2) res = res * a % oo;
        n /= 2;
        a = a * a % oo;
    }
    return res;
}

ll nCk(int n, int k) {
    if (k > n) return 0;
    return fac[n] * power(fac[k], oo-2) % oo * power(fac[n-k], oo-2) % oo;
}

#define multi_test 1
void _main() {
    int n, k; cin >> n >> k;
    fac[0] = 1;
    fto (i, 1, n) {
        fac[i] = fac[i-1] * i % oo;
        cnt[i] = need[i] = 0;
    }
    fto (i, 1, n) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    sort(a+1, a+1+n, greater<int>());
    fto (i, 1, k) ++need[a[i]];
    ll ans = 1;
    fto (i, 1, k) {
        if (!need[a[i]]) continue;
        ans *= nCk(cnt[a[i]], need[a[i]]);
        ans %= oo;
        need[a[i]] = 0;
    }
    bug(ans);
}

int main() {
    #ifdef _LOCAL
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    if (multi_test) cin >> t;
    while (t--) {
        _main();
    }

    #ifdef _LOCAL
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}