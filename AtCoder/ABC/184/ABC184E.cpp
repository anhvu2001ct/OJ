#ifdef _LOCAL
    #include "cp_debug.hpp"
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
int const maxn = 2e3+3;

int n, m;
ii s, t;
vector<ii> pos['z'+1];
char a[maxn][maxn];
bool flag['z'+1];
int ans[maxn][maxn];
 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
 
void bfs() {
    queue<ii> q;
    q.push(s);
    ans[s.ff][s.ss] = 1;
    while (!q.empty()) {
        ii u = q.front();
        if (u == t) break;
        q.pop();
        fto1 (i, 0, 4) {
            ii v = {u.ff + dy[i], u.ss + dx[i]};
            if (v.ff > 0 && v.ff <= n && v.ss > 0 && v.ss <= m && a[v.ff][v.ss] != '#' && !ans[v.ff][v.ss]) {
                ans[v.ff][v.ss] = ans[u.ff][u.ss] + 1;
                q.push(v);
            }
        }
        if (a[u.ff][u.ss] >= 'a' && a[u.ff][u.ss] <= 'z' && !flag[a[u.ff][u.ss]]) {
            flag[a[u.ff][u.ss]] = 1;
            fat (v, pos[a[u.ff][u.ss]]) {
                if (!ans[v.ff][v.ss]) {
                    ans[v.ff][v.ss] = ans[u.ff][u.ss] + 1;
                    q.push(v);
                }
            }
        }
    }
    --ans[t.ff][t.ss];
}
 
#define multi_test 0
void _main() {
    cin >> n >> m;
    fto (i, 1, n) {
        fto (j, 1, m) {
            cin >> a[i][j];
            if (a[i][j] == 'S') s = {i, j};
            else if (a[i][j] == 'G') t = {i, j};
            else if (a[i][j] >= 'a' && a[i][j] <= 'z') pos[a[i][j]].push_back({i, j});
        }
    }
    bfs();
    bug(ans[t.ff][t.ss]);
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