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

int n;
ii a[maxn];
bool visited[maxn];

#define multi_test 0
void _main() {
    cin >> n;
    ll ans = 0;
    fto (i, 1, n) {
        cin >> a[i].first >> a[i].second;
        ans += a[i].second;
    }
    sort(a+1, a+1+n);
    set<pll> q;
    q.insert({0, 1});
    while (!q.empty()) {
        ll d = q.begin()->first;
        int u = q.begin()->second;
        q.erase(q.begin());
        if (visited[u]) continue;
        visited[u] = 1;
        if (u == n) {
            ans += d;
            break;
        }
        if (u > 1) q.insert({d, u-1});
        auto it = upper_bound(a+1, a+1+n, ii(a[u].first + a[u].second, 0));
        if (it-a-1 > u) q.insert({d, it-a-1});
        if (it != a+1+n) q.insert({d + a[it-a].first - a[u].first - a[u].second, it-a});
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