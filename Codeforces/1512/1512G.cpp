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
int const maxn = 1e7+3;

int p[maxn], ans[maxn];
ll d[maxn];

void sieve(int n) {
    fto (i, 2, n) p[i] = i;
    for (int i = 2; (ll)i * i <= n; ++i) {
        if (p[i] != i) continue;
        for (int j = i*i; j <= n; j += i) p[j] = min(p[j], i);
    }
}

#define multi_test 0
void _main() {
    int n = 1e7;
    sieve(n);
    d[1] = 1;
    fto (i, 2, n) {
        int j = i;
        int val = 1;
        ll sum = 1;
        while (j%p[i] == 0) {
            val *= p[i];
            sum += val;
            j /= p[i];
        }
        d[i] = sum * d[j];
    }
    fto (i, 1, n) ans[i] = oo;
    fto (i, 1, n) {
        if (d[i] > n) continue;
        ans[d[i]] = min(ans[d[i]], i);
    }
    int q; cin >> q;
    while (q--) {
        int c; cin >> c;
        bug(ans[c] == oo ? -1 : ans[c]);
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