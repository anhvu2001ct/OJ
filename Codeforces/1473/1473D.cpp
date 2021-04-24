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
string s;
pair<int, ii> st[4*maxn];

pair<int, ii> merge(pair<int, ii> const &l, pair<int, ii> const &r) {
    int mx = max(l.ss.ff, l.ff + r.ss.ff);
    int mn = min(l.ss.ss, l.ff + r.ss.ss);
    return {l.ff + r.ff, {mx, mn}};
}

void build(int id, int l, int r) {
    if (l == r) {
        if (s[l] == '-') st[id] = {-1, {0, -1}};
        else st[id] = {1, {1, 0}};
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    st[id] = merge(st[2*id], st[2*id+1]);
}

pair<int, ii> get(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return {0, {0, 0}};
    if (ql <= l && qr >= r) return st[id];
    int mid = (l+r)/2;
    return merge(get(2*id, l, mid, ql, qr), get(2*id+1, mid+1, r, ql, qr));
}

#define multi_test 1
void _main() {
    cin >> n >> m;
    cin >> s; s = " " + s;
    build(1, 1, n);
    while (m--) {
        int l, r; cin >> l >> r;
        pair<int, ii> val = {0, {0, 0}};
        if (l > 1) val = get(1, 1, n, 1, l-1);
        if (r < n) val = merge(val, get(1, 1, n, r+1, n));
        bug(val.ss.ff - val.ss.ss + 1);
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