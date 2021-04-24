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

int n, m;
vector<int> v1, v2;
int a[maxn];

#define multi_test 1
void _main() {
    cin >> n >> m;
    v1.clear();
    v2.clear();
    fto (i, 1, n) cin >> a[i];
    fto (i, 1, n) {
        int x; cin >> x;
        if (x == 1) v1.push_back(i);
        else v2.push_back(i);
    }

    sort(all(v1), [](int l, int r) {
        return a[l] > a[r];
    });
    sort(all(v2), [](int l, int r) {
        return a[l] > a[r];
    });

    ll sum = 0;
    int point = 0, ans = oo;
    fto1 (i, 0, sz(v2)) {
        sum += a[v2[i]];
        point += 2;
        if (sum >= m) ans = min(ans, point);
    }
    int r = sz(v2)-1;
    fto1 (i, 0, sz(v1)) {
        ++point;
        sum += a[v1[i]];
        while (sum >= m && r >= 0) {
            sum -= a[v2[r]];
            if (sum < m) {
                sum += a[v2[r]];
                break;
            }
            --r;
            point -= 2;
        }
        if (sum >= m) ans = min(ans, point);
    }
    bug(ans == oo ? -1 : ans);
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