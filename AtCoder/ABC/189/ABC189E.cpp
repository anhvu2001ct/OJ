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
int const maxn = 2e5+3;

struct matrix {
    array<array<ll, 3>, 3> cell;
};

int n, m, q;
ii a[maxn];
matrix b[maxn];

matrix multiply(matrix &A, matrix &B) {
    matrix C;
    fto1 (i, 0, 3) {
        fto1 (j, 0, 3) {
            C.cell[i][j] = 0;
            fto1 (k, 0, 3) {
                C.cell[i][j] += A.cell[i][k] * B.cell[k][j];
            }
        }
    }
    return C;
}

#define multi_test 0
void _main() {
    b[0] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };

    cin >> n;
    fto (i, 1, n) cin >> a[i].ff >> a[i].ss;
    cin >> m;
    int t, p;
    fto (i, 1, m) {
        cin >> t;
        if (t == 1) {
            b[i].cell = {
                0, -1, 0,
                1, 0, 0,
                0, 0, 1
            };
        } else if (t == 2) {
            b[i].cell = {
                0, 1, 0,
                -1, 0, 0,
                0, 0, 1
            };
        } else if (t == 3) {
            cin >> p;
            b[i].cell = {
                -1, 0, 0,
                0, 1, 0,
                2*p, 0, 1
            };
        } else {
            cin >> p;
            b[i].cell = {
                1, 0, 0,
                0, -1, 0,
                0, 2*p, 1
            };
        }
        b[i] = multiply(b[i-1], b[i]);
    }

    cin >> q;
    while (q--) {
        cin >> t >> p;
        cout << a[p].ff * b[t].cell[0][0] + a[p].ss * b[t].cell[1][0] + b[t].cell[2][0] << ' ';
        cout << a[p].ff * b[t].cell[0][1] + a[p].ss * b[t].cell[1][1] + b[t].cell[2][1] << endl;
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