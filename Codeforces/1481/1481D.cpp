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

int n, m;
string a[maxn];

#define multi_test 1
void _main() {
    cin >> n >> m;
    fto1 (i, 0, n) cin >> a[i];
    if (m%2) {
        bug("YES");
        fto (i, 0, m) cout << (i%2)+1 << ' ';
        bug("");
        return;
    }
    fto1 (i, 0, n) {
        fto1 (j, i+1, n) {
            if (a[i][j] == a[j][i]) {
                bug("YES");
                fto (k, 0, m) cout << (k%2 ? (j+1) : (i+1)) << ' ';
                bug("");
                return;
            }
        }
    }
    if (n == 2) {
        bug("NO");
        return;
    }
    bug("YES");
    int x = 0, y = 1, z = 2;
    if (a[x][y] != a[y][z]) {
        int _x = z, _y = x, _z = y;
        if (a[z][x] == a[y][z]) {
            _x = y, _y = z, _z = x;
        }
        x = _x;
        y = _y;
        z = _z;
    }
    ++x; ++y; ++z;
    if ((m/2)%2) {
        fto (i, 0, m) {
            if (i%4 == 0) cout << x << ' ';
            else if (i%4 == 1) cout << y << ' ';
            else if (i%4 == 2) cout << z << ' ';
            else cout << y << ' ';
        }
        bug("");
    } else {
        fto (i, 0, m) {
            if (i%4 == 0) cout << y << ' ';
            else if (i%4 == 1) cout << z << ' ';
            else if (i%4 == 2) cout << y << ' ';
            else cout << x << ' ';
        }
        bug("");
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