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
int const maxn = 1e3+3;

int n, m;
vector<ii> adj[maxn];
vector<ii> a[maxn][maxn];
ll d[maxn][maxn];

void bfs() {
    queue<ii> q;
    q.push({1, n});
    d[1][n] = 1;
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        fat (v, a[u.first][u.second]) {
            if (!d[v.first][v.second]) {
                d[v.first][v.second] = d[u.first][u.second] + 1;
                q.push(v);
            }
        }
    }
}

#define multi_test 0
void _main() {
    cin >> n >> m;
    fto (i, 1, m) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    fto (i, 1, n) {
        fto (j, 1, n) {
            fat (u, adj[i]) {
                fat (v, adj[j]) {
                    if (u.second != v.second) continue;
                    a[i][j].push_back({u.first, v.first});
                }
            }
        }
    }
    bfs();
    ll ans = OO;
    fto (i, 1, n) {
        if (d[i][i]) ans = min(ans, (d[i][i]-1)*2);
        fat (u, adj[i]) if (d[i][u.first]) ans = min(ans, (d[i][u.first]-1)*2 + 1);
    }
    bug(ans == OO ? -1 : ans);
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