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
int const maxn = 1e5+3;

int n;
vector<int> adj[maxn];
vector<set<ll>> data;
int a[maxn], in[maxn], id[maxn], ans[maxn];
ll cnt[maxn];
ii path[maxn];

void dfs(int u) {
    fat (v, adj[u]) {
        if (id[u] == -1) id[u] = id[v];
        if (id[u] != id[v]) {
            fat (val, data[id[v]]) {
                data[id[u]].insert(val + cnt[id[v]] - cnt[id[u]]);
            }
        }
    }
    data[id[u]].insert(a[u] - cnt[id[u]]);
    ans[u] = sz(data[id[u]]);
    int v = path[u].first;
    if (!v) return;
    cnt[id[u]] += path[u].second;
    if (++in[v] == sz(adj[v])) dfs(v);
}

#define multi_test 0
void _main() {
    cin >> n;
    fto (i, 1, n) {
        cin >> a[i];
        id[i] = -1;
    }
    fto (i, 1, n) {
        cin >> path[i].first;
        adj[path[i].first].push_back(i);
    }
    fto (i, 1, n) cin >> path[i].second;
    fto (i, 1, n) if (!sz(adj[i])) {
        id[i] = sz(data);
        data.push_back(set<ll>());
        dfs(i);
    }
    fto (i, 1, n) bug(ans[i]);
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