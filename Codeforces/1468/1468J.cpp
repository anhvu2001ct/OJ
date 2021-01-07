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
int const maxn = 2e5+3;

int n, m, k;
int p[maxn];
vector<pair<ii, ii>> edge;

int par(int u) {
    return u == p[u] ? u : p[u] = par(p[u]);
}

bool Union(int u, int v) {
    u = par(u); v = par(v);
    p[v] = u;
    return u != v;
}

#define multi_test 1
void _main() {
    cin >> n >> m >> k;
    edge.clear();
    fto (i, 1, n) p[i] = i;
    
    int u, v, w;
    fto (i, 1, m) {
        cin >> u >> v >> w;
        edge.push_back({{w-k, w}, {u, v}});
    }

    sort(all(edge));
    ll ans = 0;
    fto1 (i, 0, m) {
        u = edge[i].ss.ff, v = edge[i].ss.ss;
        if (Union(u, v)) {
            if (edge[i].ff.ff > 0) ans += edge[i].ff.ff;
        }
    }

    if (ans > 0) bug(ans);
    else {
        ans = OO;
        fto1 (i, 0, m) {
            if (edge[i].ff.ff > 0) ans = min(ans, (ll)edge[i].ff.ff);
            else ans = min(ans, -(ll)edge[i].ff.ff);
        }
        bug(ans);
    }
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