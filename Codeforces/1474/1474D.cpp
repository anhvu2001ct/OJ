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

int n;
ll a[maxn], b1[maxn], b2[maxn];

#define multi_test 1
void _main() {
    cin >> n;
    fto (i, 1, n) cin >> a[i];
    b1[1] = a[1];
    fto (i, 2, n) {
        if (b1[i-1] <  0) b1[i] = -1;
        else b1[i] = a[i] - b1[i-1];
    }
    b2[n+1] = 0;
    b2[n] = a[n];
    fdto (i, n-1, 1) {
        if (b2[i+1] < 0) b2[i] = -1;
        else b2[i] = a[i] - b2[i+1];
    }
    if (b1[n] == 0) {
        bug("YES");
        return;
    }
    fto1 (i, 1, n) {
        if (b1[i-1] < 0 || b2[i+2] < 0) continue;
        swap(a[i], a[i+1]);
        ll v1 = a[i] - b1[i-1];
        ll v2 = a[i+1] - b2[i+2];
        if (v1 == v2 && v1 >= 0) {
            bug("YES");
            return;
        }
        swap(a[i], a[i+1]);
    }
    bug("NO");
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