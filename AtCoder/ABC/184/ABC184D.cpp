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
int const maxn = 1e2+3;
 
double ans[maxn][maxn][maxn];
 
#define multi_test 0
void _main() {
    int a, b, c;
    cin >> a >> b >> c;
    fdto (i, 100, 0) {
        fdto (j, 100, 0) {
            fdto (k, 100, 0) {
                if (i == 100 || j == 100 || k == 100 || i+j+k == 0) continue;
                int sum = i+j+k;
                ans[i][j][k] = (ans[i+1][j][k] + 1)*(1.0*i / sum);
                ans[i][j][k] += (ans[i][j+1][k] + 1)*(1.0*j / sum);
                ans[i][j][k] += (ans[i][j][k+1] + 1)*(1.0*k / sum);
            }
        }
    }
    cout << fixed << setprecision(9);
    bug(ans[a][b][c]);
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