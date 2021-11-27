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
vector<ii> adj[maxn];
vector<int> cur;
vector<pair<ii, ii>> ans;
bool flag[maxn], visited[maxn], leaf[maxn];

int dfs(int u, int p) {
    int child = 0;
    for (auto [v, id]: adj[u]) {
        if (v == p) continue;
        int num = dfs(v, u);
        if (num == 2) flag[id] = 1, ans.push_back({{u, v}, {0, 0}});
        else ++child;
    }
    for (auto [v, id]: adj[u]) {
        if (child <= 2) break;
        if (v == p) continue;
        if (!flag[id]) flag[id] = 1, ans.push_back({{u, v}, {0, 0}}), --child;
    }
    return child;
}

void dfs2(int u, int root) {
    visited[u] = 1;
    cur.push_back(u);
    int child = 0;
    for (auto [v, id]: adj[u]) {
        if (!visited[v] && !flag[id]) {
            dfs2(v, root);
            ++child;
        }
    }
    leaf[u] = (u == root && child == 1) || !child;
}

#define multi_test 1
void _main() {
    cin >> n;
    ans.clear();
    fto (i, 1, n) {
        adj[i].clear();
        flag[i] = visited[i] = leaf[i] = 0;
    }
    fto1 (i, 1, n) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dfs(1, 0);
    vector<vector<int>> compo;
    fto (i, 1, n) {
        if (!visited[i]) {
            cur.clear();
            dfs2(i, i);
            compo.push_back({});
            for (auto u: cur) {
                if (leaf[u]) compo.back().push_back(u);
            }
        }
    }
    int cnt = 0;
    fto1 (i, 1, sz(compo)) {
        ans[cnt++].second = {compo[i-1].back(), compo[i].front()};
    }
    bug(sz(ans));
    for (auto &val: ans) bug(val.first.first, val.first.second, val.second.first, val.second.second);
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