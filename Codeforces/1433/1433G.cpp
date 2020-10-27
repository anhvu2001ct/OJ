#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
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
#define bug(...) _bug(cout, __VA_ARGS__)
#define bugn(...) _bugn(#__VA_ARGS__, __VA_ARGS__)
#define buga(a, s, e) cout << '{'; fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
    return os << '(' << v.ff << ", " << v.ss << ')';
}

template<typename T>
void _bug(ostream &os, T const &var) { os << var << endl; }

template<typename T, typename... Args>
void _bug(ostream &os, T const &var, Args const &... args) {
    os << var << ' ';
    _bug(os, args...);
}

template<typename... Args>
void _bugn(string const &s, Args const &... args) {
    auto split = [](string const &s, string const &delim) {
        int next, pos = 0;
        vector<string> res;
        while (1) {
            next = s.find(delim, pos);
            if (next == string::npos) break;
            res.push_back(s.substr(pos, next-pos));
            pos = next+sz(delim);
        }
        res.push_back(s.substr(pos));
        return res;
    };

    ostringstream os; _bug(os, args...);
    string tmp = os.str(); tmp.pop_back(); 
    vector<string> v1 = split(s, ", "), v2 = split(tmp, " ");
    fto1 (i, 0, sz(v1)) cout << '[' << v1[i] << ": " << v2[i] << "]" << " \n"[i == sz(v1)-1];
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e3+3;

int n, m, k;
int d[maxn][maxn];
ii a[maxn];
vector<ii> adj[maxn];

void dijkstra(int root) {
    fto (i, 1, n) d[root][i] = oo;
    d[root][root] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, root});
    while (!q.empty()) {
        int u = q.top().ss;
        q.pop();
        fat (e, adj[u]) {
            int v = e.ff;
            int total = d[root][u] + e.ss;
            if (d[root][v] > total) {
                d[root][v] = total;
                q.push({total, v});
            }
        }
    }
}

#define multi_test 0
void _main() {
    cin >> n >> m >> k;
    vector<ii> edge;
    fto (i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edge.push_back({u, v});
    }
    fto (i, 1, k) cin >> a[i].ff >> a[i].ss;
    fto (i, 1, n) dijkstra(i);
    ll ans = OO;
    fto1 (i, 0, m) {
        ll res = 0;
        int u = edge[i].ff, v = edge[i].ss;
        fto (j, 1, k) {
            int s = a[j].ff, t = a[j].ss;
            res += min(d[s][t], min(d[s][u] + d[v][t], d[s][v] + d[u][t]));
        }
        ans = min(ans, res);
    }
    bug(ans);
}

int main() {
    #ifdef KITTENS
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    if (multi_test) cin >> t;
    while (t--) {
        _main();
    }

    #ifdef KITTENS
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}