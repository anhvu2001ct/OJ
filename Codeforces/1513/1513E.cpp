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

int n;
int a[maxn];
ll fac[maxn];

ll power(ll a, int n) {
    ll res = 1;
    while (n) {
        if (n%2) res = res * a % oo;
        n >>= 1;
        a = a * a % oo;
    }
    return res;
}

#define multi_test 0
void _main() {
    cin >> n;
    fac[0] = 1;
    ll sum = 0;
    fto (i, 1, n) {
        fac[i] = fac[i-1] * i % oo;
        cin >> a[i];
        sum += a[i];
    }
    if (sum%n) {
        bug(0);
        return;
    }
    int x = sum/n;
    int left = 0, right = 0, mid = 0;
    map<int, int> lval, rval;
    fto (i, 1, n) {
        if (a[i] < x) ++left, ++lval[a[i]];
        else if (a[i] == x) ++mid;
        else ++right, ++rval[a[i]];
    }
    if (!left) {
        bug(1);
        return;
    }
    ll ans = (fac[n] * power(fac[mid], oo-2) % oo) * power(fac[n-mid], oo-2) % oo;
    ans = ans * fac[left] % oo;
    for (auto [_, cnt]: lval) ans = ans * power(fac[cnt], oo-2) % oo;
    ans = ans * fac[right] % oo;
    for (auto [_, cnt]: rval) ans = ans * power(fac[cnt], oo-2) % oo;
    if (left == 1 || right == 1) bug(ans * (n-mid) % oo);
    else bug(ans * 2 % oo);
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