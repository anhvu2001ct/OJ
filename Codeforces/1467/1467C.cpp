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
int const maxn = 3e5+3;

int n[3];
ll sum[3];
vector<int> a[3];

#define multi_test 0
void _main() {
    fto1 (i, 0, 3) cin >> n[i];
    fto1 (i, 0, 3) {
        fto1 (j, 0, n[i]) {
            a[i].push_back(0);
            cin >> a[i].back();
        }
        sort(all(a[i]));
    }

    ll ans = 0;
    fto1 (i, 0, 3) {
        swap(a[0], a[i]);
        fto1 (i1, 0, 3) {
            sum[i1] = 0;
            fto1 (j, 0, sz(a[i1])) sum[i1] += a[i1][j];
        }
        ans = max(ans, sum[0] + max({sum[1] + sum[2] - 2LL*(a[1][0] + a[2][0]), sum[1] - sum[2], sum[2] - sum[1]}));
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