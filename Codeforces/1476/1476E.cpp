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

int n, m, k;
vector<int> ans;
unordered_map<string, vector<int>> cnt;
string a[maxn];
vector<string> d[maxn];
int status[maxn], b[maxn];

void dfs(int u) {
    status[u] = 1;
    fat (s, d[u]) fat (v, cnt[s]) {
        if (u == v) continue;
        if (status[v] == 1) ans[0] = -1;
        else if (!status[v]) dfs(v);
        if (ans[0] == -1) return;
    }
    status[u] = 2;
    ans.push_back(u);
}

void solve() {
    ans.push_back(0);
    fto (i, 1, n) if (!status[i]) dfs(i);
    if (ans[0] == -1) {
        bug("NO");
        return;
    }
    bug("YES");
    fdto (i, sz(ans)-1, 1) cout << ans[i] << ' ';
}

#define multi_test 0
void _main() {
    cin >> n >> m >> k;
    fto (i, 1, n) {
        cin >> a[i];
        cnt[a[i]].push_back(i);
    }
    int N = 1 << k;
    fto (i, 1, m) {
        string s; cin >> s >> b[i];
        bool flag = 0;
        fto1 (_i, 0, N) {
            string tmp = s;
            fto1 (j, 0, k) if ((_i & (1 << j)) == 0) {
                tmp[k-j-1] = '_';
            }
            if (cnt.count(tmp)) d[b[i]].push_back(tmp);
            if (a[b[i]] == tmp) flag = 1;
        }
        if (!flag) {
            bug("NO");
            return;
        }
    }
    solve();
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