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

int n, l, r, s;
int a[1000];

#define multi_test 1
void _main() {
    cin >> n >> l >> r >> s;
    int cnt = r-l+1;
    int vmin = cnt*(1+cnt)/2;
    int vmax = cnt*(n+(n-cnt+1))/2;
    if (s >= vmin && s <= vmax) {
        fto (i, 1, cnt) a[i] = i;
        a[cnt+1] = n+1;
        int pos = cnt;
        while (vmin < s) {
            if (a[pos] == a[pos+1]-1) --pos;
            ++a[pos];
            ++vmin;
        }
        vector<int> ans(n+1);
        pos = 0;
        map<int, bool> tmp;
        fto (i, l, r) {
            ans[i] = a[++pos];
            tmp[ans[i]] = 1;
        }
        int val = 1;
        fto (i, 1, l-1) {
            while (tmp.count(val)) ++val;
            ans[i] = val++;
        }
        fto (i, r+1, n) {
            while (tmp.count(val)) ++val;
            ans[i] = val++;
        }
        fto (i, 1, n) cout << ans[i] << ' ';
        bug("");
    } else bug(-1);
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