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
int const maxn = 1e2+3;

vector<int> vec[maxn];
int a[maxn][maxn], g[maxn][maxn], ans[maxn][maxn];
int f[maxn][maxn][maxn];


#define multi_test 0
void _main() {
    int n, m, k;
    cin >> n >> m >> k;
    fto (i, 1, n) {
        fto (j, 1, m) {
            cin >> a[i][j];
        }

        fto (j, 0, m) fto (c, 0, m/2) fto1 (d, 0, k) {
            if (c == 0 && d == 0) continue;
            f[j][c][d] = -1;
        }

        fto (j, 1, m) {
            fto (c, 1, m/2) {
                fto1 (d, 0, k) {
                    int need = ((d - a[i][j])%k + k)%k;
                    f[j][c][d] = f[j-1][c][d];
                    if (f[j-1][c-1][need] != -1) {
                        f[j][c][d] = max(f[j][c][d], f[j-1][c-1][need] + a[i][j]);
                    }
                }
            }
        }

        fto (c, 1, m/2) fto1 (d, 0, k) g[i][d] = max(g[i][d], f[m][c][d]);

        fto1 (d, 0, k) {
            ans[i][d] = ans[i-1][d];
            fto1 (j, 0, k) {
                if (!g[i][j]) continue;
                int need = ((d-j)%k + k)%k;
                if (ans[i-1][need] || need == 0) ans[i][d] = max(ans[i][d], ans[i-1][need] + g[i][j]);
            }
        }
    }
    bug(ans[n][0]);
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