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
int const maxn = 2e5+5;

int n;
ii a[maxn];
int pre[maxn];
vector<ii> X, Y;

ll calc(vector<ii> &X, vector<ii> &Y) {
    pre[sz(Y)] = oo;
    fdto (i, sz(Y)-1, 0) pre[i] = min(pre[i+1], Y[i].second);
    
    int res = 0;
    for (auto &p: X) {
        auto it = lower_bound(all(Y), ii(p.first, 0));
        if (it != Y.end()) {
            int val = max(p.second, pre[it - Y.begin()]);
            if (val <= p.first) res = max(res, p.first - val);
        }
    }
    return res*2;
}

#define multi_test 0
void _main() {
    cin >> n;
    fto (i, 1, n) cin >> a[i].first;
    fto (i, 1, n) cin >> a[i].second;

    ll ans = 0;
    fto (i, 1, n) {
        if (a[i].first < a[i].second) X.push_back({a[i].second, a[i].first});
        else if (a[i].first > a[i].second) Y.push_back(a[i]);
        ans += abs(a[i].second - a[i].first);
    }
    sort(all(X)); sort(all(Y));

    ans -= max(calc(X, Y), calc(Y, X));
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