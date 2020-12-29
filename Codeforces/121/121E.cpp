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
int const maxn = 1e5+3;

int n;
int child[maxn];
bool ans[maxn];
vector<int> a[maxn];

int dfs(int u, int p) {
    child[u] = 1;
    fat (v, a[u]) {
        if (v == p) continue;
        child[u] += dfs(v, u);
    }

    static vector<int> branch;
    branch.clear();

    fat (v, a[u]) {
        if (v != p) branch.push_back(child[v]);
    }

    vector<bool> avail(n, 0), tmp;
    avail[0] = 1;
    fat (v, branch) {
        tmp = avail;
        fto1 (i, v, n) {
            avail[i] = avail[i] | tmp[i-v];
        }
    }

    fto1 (i, 1, n) ans[i] |= avail[i];

    return child[u];
}

#define multi_test 0
void _main() {
    cin >> n;
    int u, v;
    fto1 (i, 1, n) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0);

    int cnt = 0;
    fto1 (i, 1, n-1) if (ans[i]) ans[n-i-1] = 1;
    fto1 (i, 1, n-1) cnt += ans[i];
    bug(cnt);
    fto1 (i, 1, n-1) if (ans[i]) bug(i, n-i-1);
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