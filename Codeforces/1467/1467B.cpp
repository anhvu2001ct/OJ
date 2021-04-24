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

int n;
int a[maxn];

bool check(int i) {
    if (a[i] > a[i-1] && a[i] > a[i+1]) return 1;
    if (a[i] < a[i-1] && a[i] < a[i+1]) return 1;
    return 0;
}

#define multi_test 1
void _main() {
    cin >> n;
    fto (i, 1, n) cin >> a[i];
    int ans = 0;
    fto1 (i, 2, n) ans += check(i);

    a[0] = a[1];
    a[n+1] = a[n];
    
    int res = ans;
    fto (i, 1, n) {
        if (i == 1) ans = min(ans, res - check(i+1));
        else if (i == n) ans = min(ans, res - check(i-1));
        else {
            int tmp = a[i];
            int val[2] = {a[i-1], a[i+1]};
            fat (v, val) {
                int cur = res - check(i);
                cur -= check(i-1);
                cur -= check(i+1);
                a[i] = v;
                cur += check(i-1);
                cur += check(i+1);
                ans = min(ans, cur);
                a[i] = tmp;
            }
        }
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