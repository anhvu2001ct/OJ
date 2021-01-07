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
int h[maxn], w[maxn], b[maxn], ans[maxn];
ii a[maxn];

void solve1() {
    fto (i, 1, n) b[i] = i;
    sort(b+1, b+1+n, [&](int l, int r) {
        return a[l] < a[r];
    });

    set<ii> cur;
    vector<ii> save;
    fto (i, 1, n) {
        auto it = cur.lower_bound(ii(a[b[i]].ss, 0));
        if (it != cur.begin()) {
            --it;
            ans[b[i]] = it->ss;
        }
        save.push_back(ii(a[b[i]].ss, b[i]));
        if (i < n && a[b[i]].ff < a[b[i+1]].ff) {
            fat (val, save) cur.insert(val);
            save.clear();
        }
    }
}

void solve2() {
    fto (i, 1, n) h[i] = w[i] = i;
    sort(h+1, h+1+n, [&](int l, int r) {
        return a[l].ff < a[r].ff;
    });
    sort(w+1, w+1+n, [&](int l, int r) {
        return a[l].ss < a[r].ss;
    });

    int l = 1;
    set<ii> cur;
    fto (i, 1, n) {
        while (l <= n && a[w[l]].ss < a[h[i]].ff) {
            cur.insert({a[w[l]].ff, w[l]});
            ++l;
        }
        if (!cur.empty()) {
            auto it = cur.begin();
            if (it->ss == h[i]) ++it;
            if (it != cur.end() && it->ff < a[h[i]].ss) ans[h[i]] = it->ss;
        }
    }
}

#define multi_test 1
void _main() {
    cin >> n;
    fto (i, 1, n) {
        cin >> a[i].ff >> a[i].ss;
        ans[i] = -1;
    }

    solve1();
    solve2();
    fto (i, 1, n) cout << ans[i] << ' ';
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