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
int const maxn = 1e6+3;

int n;
int p[maxn];
map<int, int> cnt;

void sieve(int n) {
    fto (i, 1, n) p[i] = i;
    for (int i = 2; (ll)i*i <= n; ++i) {
        if (p[i] == i) for (int j = i*i; j <= n; j += i) {
            p[j] = min(p[j], i);
        }
    }
}

#define multi_test 1
void _main() {
    static bool flag = 0;
    if (!flag) {
        flag = 1;
        sieve(1e6);
    }

    cin >> n;
    cnt.clear();

    int ans = 0;
    fto (i, 1, n) {
        int x; cin >> x;
        int add = 1, id = 1;
        while (x > 1) {
            int next = x / p[x];
            if (p[x] == p[next]) add ^= 1;
            else {
                if (add) id *= p[x];
                add = 1;
            }
            x = next;
        }
        ans = max(ans, ++cnt[id]);
    }

    int max_ans = 0;
    fat (p, cnt) {
        if (p.ss%2 == 0 || p.ff == 1) max_ans += p.ss;
    }
    max_ans = max(max_ans, ans);

    int q; cin >> q;
    while (q--) {
        ll w; cin >> w;
        bug(w == 0 ? ans : max_ans);
    }
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