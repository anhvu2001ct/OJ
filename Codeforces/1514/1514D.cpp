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
int const maxn = 3e5+5;

int n, q;
int a[maxn];
vector<int> pos[maxn];

int random(int left, int right) {
    static mt19937 rg(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<>(left, right)(rg);
}

int freq(int val, int left, int right) {
    auto r = upper_bound(all(pos[val]), right);
    if (r == pos[val].begin()) return 0;
    auto l = lower_bound(all(pos[val]), left);
    if (l == pos[val].end()) return 0;
    return r-l;
}

#define multi_test 0
void _main() {
    cin >> n >> q;
    fto (i, 1, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        int mid = (r-l+2)/2;
        int ans = 1;
        fto1 (_, 0, 35) {
            int val = a[random(l, r)];
            int f = freq(val, l, r);
            if (f > mid) {
                ans = 2*f - (r-l+1);
                break;
            }
        }
        bug(ans);
    }
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