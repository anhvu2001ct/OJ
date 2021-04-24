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
int const maxn = 2e5+5;

int n, k;
int a[maxn], l[maxn][25], f[maxn][25];
int p[int(1e7+5)], cnt[int(1e7+5)];

void sieve(int n) {
    fto (i, 2, n) p[i] = i;
    for (int i = 2; (ll)i * i <= n; ++i) {
        if (p[i] == i) for (int j = i * i; j <= n; j += i)
            p[j] = min(p[j], i);
    }
}

int calc(int n) {
    int res = 1;
    int cur = 0, cnt = 0;
    while (n > 1) {
        if (cur != p[n]) {
            if (cur && cnt%2) res *= cur;
            cur = p[n];
            cnt = 0;
        }
        ++cnt;
        n /= p[n];
    }
    if (cnt%2) res *= cur;
    return res;
}

#define multi_test 0
void _main() {
    sieve(1e7);
    int q; cin >> q;
    while (q--) {
        cin >> n >> k;
        fto (i, 1, n) {
            cin >> a[i];
            a[i] = calc(a[i]);
        }
        fto (j, 0, k) {
            fto (i, 1, n) cnt[a[i]] = 0;
            int cur = 1, need = 0;
            fto (i, 1, n) {
                if (++cnt[a[i]] >= 2) ++need;
                while (need > j) {
                    if (--cnt[a[cur++]]) --need;
                }
                l[i][j] = cur;
            }
        }
        fto (i, 1, n) {
            fto (j, 0, k) {
                f[i][j] = oo;
                fto (x, 0, j) {
                    f[i][j] = min(f[i][j], f[l[i][x]-1][j-x] + 1);
                }
            }
        }
        bug(f[n][k]);
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