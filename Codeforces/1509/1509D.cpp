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

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define bc __builtin_popcountll
#define endl '\n'
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define buga(a, s, e) fto(__i, s, e) cout << a[__i] << " \n"[__i == e];
#define bugar(a, s, e) cout << '{'; if (e < s) cout << '}'; else fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

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
int const maxn = 1e5+5;

int n;
string s[3];
int p[3];

#define multi_test 1
void _main() {
    cin >> n;
    fto1 (i, 0, 3) {
        cin >> s[i];
        p[i] = 0;
    }
    int m = 2*n;
    string ans;
    while (p[0] < m && p[1] < m && p[2] < m) {
        int zero = 0, one = 0;
        fto1 (i, 0, 3) {
            zero += s[i][p[i]] == '0';
            one += s[i][p[i]] == '1';
        }
        char c = (zero > one) ? '0' : '1';
        fto1 (i, 0, 3) {
            if (s[i][p[i]] == c) ++p[i];
        }
        ans += c;
    }
    fto1 (i, 0, 3) if (p[i] == m) {
        p[i] = -1;
        int pos = max_element(p, p+3)-p;
        fto1 (j, p[pos], m) ans += s[pos][j];
        break;
    }
    bug(ans);
}

int main() {
    #ifdef _LOCAL
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t = 1; if (multi_test) cin >> t;
    while (t--) _main();

    #ifdef _LOCAL
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}