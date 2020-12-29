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
int const maxn = 3e5+3;

int n, k;
bool cycle;
int cid[maxn], state[maxn];
bool check[maxn];
vector<int> a[maxn], in[maxn], out[maxn], adj[maxn];
vector<vector<int>> component;
vector<int> st;

void dfs(int u) {
    state[u] = 1;
    fat (v, adj[u]) {
        if (state[v] == 1) {
            cycle = 1;
            return;
        }
        if (state[v] == 0) dfs(v);
    }
    state[u] = 2;
    st.push_back(u);
}

#define multi_test 0
void _main() {
    int n, k; cin >> n >> k;
    fto (i, 1, n) {
        int x; cin >> x;
        if (x) a[x].push_back(i);
    }

    fto (i, 1, k) {
        int u, v; cin >> u >> v;
        in[v].push_back(u);
        out[u].push_back(v);
    }

    fto (u, 1, n) {
        if (sz(in[u]) >= 2 || sz(out[u]) >= 2) {
            bug(0);
            return;
        }
    }

    int cnt = 0;
    fto (u, 1, n) {
        if (!sz(in[u])) {
            component.push_back(vector<int>());
            vector<int> &compo = component.back();
            int v = u;
            while (1) {
                compo.push_back(v);
                cid[v] = sz(component);
                ++cnt;
                if (!sz(out[v])) break;
                v = out[v][0];
            }
        }
    }

    if (cnt < n) {
        bug(0);
        return;
    }

    fat (&compo, component) {
        fat (u, compo) {
            fat (v, a[u]) {
                if (cid[u] == cid[v]) continue;
                adj[cid[u]].push_back(cid[v]);
            }
        }
    }

    fto (i, 1, sz(component)) {
        if (!state[i]) dfs(i);
        if (cycle) {
            bug(0);
            return;
        }
    }

    reverse(all(st));
    vector<int> ans;
    fat (order, st) {
        fat (u, component[order-1]) ans.push_back(u);
    }

    fat (u, ans) {
        fat (v, a[u]) if (check[v]) {
            bug(0);
            return;
        }
        check[u] = 1;
    }
    fat (u, ans) cout << u << ' ';
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