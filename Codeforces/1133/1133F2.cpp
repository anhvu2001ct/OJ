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
#define bug(...) _bug(cout, __VA_ARGS__)
#define buga(a, s, e) cout << '{'; if (e < s) cout << '}'; else fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

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

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 2e5+3;

int n, m, D;
int p[maxn];
bool visited[maxn];
vector<ii> ans, cur, second;
vector<int> a[maxn];

void dfs(int u) {
    visited[u] = 1;
    fat (v, a[u]) {
        if (visited[v]) continue;
        cur.push_back({u, v});
        dfs(v);
    }
}

int par(int u) {
    return u == p[u] ? u : (p[u] = par(p[u]));
}

bool Union(int u, int v) {
    u = par(u), v = par(v);
    if (u == v) return 0;
    p[v] = u;
    return 1;
}

#define multi_test 0
void _main() {
    cin >> n >> m >> D;
    int u, v;
    fto (i, 1, m) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    fto (i, 1, n) p[i] = i;

    visited[1] = 1;
    int cnt = 0;
    fat (u, a[1]) {
        if (!visited[u]) {
            ans.push_back({1, u});
            Union(1, u);
            ++cnt;
            dfs(u);
        } else second.push_back({1, u});
    }

    if (cnt > D) bug("NO");
    else {
        while (cnt < D && !second.empty()) {
            ans.push_back(second.back());
            Union(1, second.back().ss);
            second.pop_back();
            ++cnt;
        }
        if (cnt < D) bug("NO");
        else {
            fat (e, cur) {
                if (Union(e.ff, e.ss)) ans.push_back(e);
            }
            bug("YES");
            fat (e, ans) bug(e.ff, e.ss);
        }
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