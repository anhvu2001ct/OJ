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
int const maxn = 1e5+3;

ll p[40];

#define multi_test 0
void _main() {
    p[0] = 1;
    fto (i, 1, 38) p[i] = p[i-1] * 3;

    int mx = 38;
    int N = mx/2;

    vector<ll> v1, v2;
    vector<pair<ll, int>> v;
    fto1 (i, 0, 1 << N) {
        ll sum1 = 0, sum2 = 0;
        fto1 (j, 0, N) {
            if (i & (1 << j)) {
                sum1 += p[j];
                sum2 += p[j+N];
            }
        }
        v1.push_back(sum1);
        v2.push_back(sum2);
    }

    v2.push_back(p[38]);

    v.reserve(sz(v1) + sz(v2));
    fto1 (i, 0, sz(v1)) v.push_back({v1[i], 1});
    fto1 (i, 0, sz(v2)) v.push_back({v2[i], 2});

    int q; cin >> q;
    while (q--) {
        ll n; cin >> n;
        auto query = upper_bound(all(v), pair<ll, int>(n, 0))-1;
        if (query->ff == n) bug(n);
        else if (query->ss == 1) bug((++query)->ff);
        else {
            auto it = lower_bound(all(v1), n - query->ff);
            if (it == v1.end()) bug((++query)->ff);
            else bug(query->ff + *it);
        }
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