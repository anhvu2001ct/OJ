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

int p[maxn];
bool check[maxn], flag[maxn];

int par(int u) {
    return p[u] < 0 ? u : p[u] = par(p[u]);
}

bool Union(int u, int v) {
    u = par(u); v = par(v);
    if (u == v) return 0;
    p[u] += p[v];
    p[v] = u;
    return 1;
}

#define multi_test 1
void _main() {
    int n, m; cin >> n >> m;
    int u, v;
    fto (i, 1, n) p[i] = -1, check[i] = flag[i] = 0;
    fto (i, 1, m) {
        cin >> u >> v;
        if (u == v) flag[u] = 1;
        else if (!Union(u, v)) check[par(u)] = 1;
    }
    int ans = 0;
    fto (i, 1, n) {
        int root = par(i);
        if (flag[root]) continue;
        flag[root] = 1;
        ans += -p[root] - 1 + 2*check[root];
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