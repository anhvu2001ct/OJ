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

int n;
ll sum, cur;
int p[maxn];
ll cnt[maxn], ans[maxn];
ii a[maxn];
vector<int> adj[maxn];

void dfs(int u) {
    fat (v, adj[u]) {
        if (v == p[u]) continue;
        p[v] = u;
        dfs(v);
    }
}

void dfs2(int u) {
    sum += cnt[u];
    ans[u] = sum + cur;
    fat (v, adj[u]) {
        if (v == p[u]) continue;
        dfs2(v);
    }
    sum -= cnt[u];
}

#define multi_test 0
void _main() {
    cin >> n;
    fto1 (i, 1, n) {
        cin >> a[i].ff >> a[i].ss;
        adj[a[i].ff].push_back(a[i].ss);
        adj[a[i].ss].push_back(a[i].ff);
    }
    dfs(1);

    int q; cin >> q;
    while (q--) {
        int t, e, x; cin >> t >> e >> x;
        if (a[e].ff == p[a[e].ss]) {
            if (t == 1) cur += x, cnt[a[e].ss] -= x;
            else cnt[a[e].ss] += x;
        } else {
            if (t == 2) cur += x, cnt[a[e].ff] -= x;
            else cnt[a[e].ff] += x;
        }
    }

    dfs2(1);
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