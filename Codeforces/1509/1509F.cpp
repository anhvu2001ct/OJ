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
int const maxn = 2e5+5;

int n, m, cnt;
int p[maxn], pre[maxn];
vector<int> adj[maxn];
vector<array<int, 3>> edge;
set<int> avai;

int par(int u, int *p) {
    return p[u] < 0 ? u : p[u] = par(p[u], p);
}

bool unify(int u, int v, int *p) {
    u = par(u, p); v = par(v, p);
    if (u == v) return 0;
    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return 1;
}

void dfs(int u) {
    avai.erase(u);
    int v = 1;
    while (1) {
        auto it = avai.lower_bound(v);
        if (it == avai.end()) return;
        v = *it;
        if (u != v && !binary_search(all(adj[u]), v)) {
            unify(u, v, p);
            ++cnt;
            dfs(v);
        }
        ++v;
    }
}

#define multi_test 0
void _main() {
    cin >> n >> m;
    int u, v, w;
    ll XOR = 0;
    fto (i, 1, m) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back({w, u, v});
        XOR ^= w;
    }

    fto (i, 1, n) {
        p[i] = pre[i] = -1;
        sort(all(adj[i]));
        avai.insert(i);
    } 

    fto (i, 1, n) if (avai.count(i)) dfs(i);

    sort(all(edge));
    ll ans = 0;
    for (auto [w, u, v]: edge) {
        if (unify(u, v, p)) {
            ans += w;
            unify(u, v, pre);
        } else if (unify(u, v, pre)) XOR = min(XOR, 1LL*w);
    }

    if (1ll*n*(n-1)/2 - m == cnt) ans += XOR;
    bug(ans);
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