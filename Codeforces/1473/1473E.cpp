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

int n, m;
ll d[maxn][2][2];
vector<ii> adj[maxn];

void dijkstra(int u) {
    fto (v, 1, n) fto (i, 0, 1) fto (j, 0, 1) {
        d[v][i][j] = OO;
    }
    set<tuple<ll, int, int, int>> q;
    d[u][0][0] = 0;
    q.insert({0, u, 0, 0});
    while (!q.empty()) {
        auto [dt, u, mn, mx] = *q.begin();
        q.erase(q.begin());
        for (auto [v, w]: adj[u]) {
            fto (i, 0, mn^1) {
                fto (j, 0, mx^1) {
                    int mn2 = mn | i, mx2 = mx | j;
                    ll total = dt + 1LL*(1 + i - j)*w;
                    if (d[v][mn2][mx2] > total) {
                        auto it = q.find({d[v][mn2][mx2], v, mn2, mx2});
                        if (it != q.end()) q.erase(it);
                        d[v][mn2][mx2] = total;
                        q.insert({total, v, mn2, mx2});
                    }
                }
            }
        }
    }
}

#define multi_test 0
void _main() {
    cin >> n >> m;
    fto (i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(1);
    fto (i, 2, n) {
        cout << d[i][1][1] << ' ';
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