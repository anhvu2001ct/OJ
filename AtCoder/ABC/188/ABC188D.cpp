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
int const maxn = 4e5+3;

int n;
ll C;
int a[maxn], b[maxn], c[maxn], in[maxn];
ll val[maxn];
vector<int> v;

#define multi_test 0
void _main() {
    cin >> n >> C;
    fto (i, 1, n) {
        cin >> a[i] >> b[i] >> c[i];
        v.push_back(a[i]);
        v.push_back(b[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    fto (i, 1, n) {
        int s = lower_bound(all(v), a[i]) - v.begin();
        int e = lower_bound(all(v), b[i]) - v.begin();
        in[s] += c[i];
        val[s] += c[i];
        val[e+1] -= c[i];
    }
    ll sum = 0, ans = 0;
    fto1 (i, 0, sz(v)) {
        sum += val[i];
        ans += min(sum, C);
        if (i) ans += min(sum - in[i], C) * (v[i] - v[i-1] - 1);
    }
    bug(ans);
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