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
int const maxn = 2e5+3;

int n, m;
int a[maxn];
vector<pll> store;

int solve(int x) {
    auto it = upper_bound(all(store), pll(x, -1));
    return it->second;
}

#define multi_test 1
void _main() {
    store.clear();
    cin >> n >> m;
    ll sum = 0;
    fto (i, 1, n) {
        cin >> a[i];
        sum += a[i];
        ll tmp = store.empty() ? 0 : store.back().first;
        if (sum > tmp) store.push_back({sum, i-1});
    }
    fto (i, 1, m) {
        ll x; cin >> x;
        if (store.empty()) {
            cout << -1 << ' ';
            continue;
        }
        ll vmax = store.back().first;
        if (x > vmax) {
            if (sum <= 0) cout << -1 << ' ';
            else {
                ll ans = (x-vmax)/sum + ((x-vmax)%sum > 0);
                x -= ans*sum;
                ans = ans*n + solve(x);
                cout << ans << ' ';
            }
        } else {
            cout << solve(x) << ' ';
        }
    }
    bug("");
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