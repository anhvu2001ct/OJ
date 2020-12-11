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
int const maxn = 2e3+3;

int n;
vector<int> row[10][maxn], col[10][maxn];

#define multi_test 1
void _main() {
    cin >> n;
    fto (d, 0, 9) fto (i, 1, n) {
        row[d][i].clear();
        col[d][i].clear();
    }
    char x;
    fto (i, 1, n) {
        fto (j, 1, n) {
            cin >> x;
            x -= '0';
            row[x][i].push_back(j);
            col[x][j].push_back(i);
        }
    }
    fto (d, 0, 9) {
        ii row_idx = {0, 0}, col_idx = {0, 0};
        fto (i, 1, n) {
            if (sz(row[d][i])) {
                if (row_idx.ff == 0) row_idx.ff = i;
                row_idx.ss = i;
            }
            if (sz(col[d][i])) {
                if (col_idx.ff == 0) col_idx.ff = i;
                col_idx.ss = i;
            }
        }
        int ans = 0;
        fto (i, 1, n) {
            if (sz(row[d][i]) == 1) {
                int width = row[d][i].back();
                width = max(width - 1, n - width);
                int height = max(abs(i - row_idx.ff), abs(i - row_idx.ss));
                ans = max(ans, height*width);
            }
            if (sz(row[d][i]) >= 2) {
                int width = row[d][i].back() - row[d][i].front();
                int height = max(i - 1, n - i);
                ans = max(ans, height*width);
                width = max(row[d][i].back() - 1, n - row[d][i].front());
                height = max(abs(i - row_idx.ff), abs(i - row_idx.ss));
                ans = max(ans, height*width);
            }
            if (sz(col[d][i]) == 1) {
                int width = col[d][i].back();
                width = max(width - 1, n - width);
                int height = max(abs(i - col_idx.ff), abs(i - col_idx.ss));
                ans = max(ans, height*width);
            }
            if (sz(col[d][i]) >= 2) {
                int width = col[d][i].back() - col[d][i].front();
                int height = max(i - 1, n - i);
                ans = max(ans, height*width);
                width = max(col[d][i].back() - 1, n - col[d][i].front());
                height = max(abs(i - col_idx.ff), abs(i - col_idx.ss));
                ans = max(ans, height*width);
            }
        }
        cout << ans << ' ';
    }
    bug("");
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