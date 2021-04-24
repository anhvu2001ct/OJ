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
#define endl '\n'
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
int const maxn = 2e5+3;

int n;
int vmin[maxn], vmax[maxn];

#define multi_test 0
void _main() {
    cin >> n;
    fto (c, 1, 2e5) vmin[c] = oo, vmax[c] = -oo;
    set<int> a;
    fto (i, 1, n) {
        int x, c;
        cin >> x >> c;
        vmin[c] = min(vmin[c], x);
        vmax[c] = max(vmax[c], x);
        a.insert(c);
    }
    ii cur = {0, 0};
    ll fmin = 0, fmax = 0;
    fat (c, a) {
        ll dt = vmax[c] - vmin[c];
        ll fmin2 = dt + min(fmin + abs(cur.first - vmax[c]), fmax + abs(cur.second - vmax[c]));
        ll fmax2 = dt + min(fmin + abs(cur.first - vmin[c]), fmax + abs(cur.second - vmin[c]));
        fmin = fmin2; fmax = fmax2;
        cur = {vmin[c], vmax[c]};
    }
    bug(min(fmin + abs(cur.first), fmax + abs(cur.second)));
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