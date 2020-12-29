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
#define bug(...) _bug(cout, __VA_ARGS__)
#define buga(a, s, e) cout << '{'; if (e < s) cout << '}'; else fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
    return os << '(' << v.ff << ", " << v.ss << ')';
}

template<typename T>
void _bug(ostream &os, T const &var) { os << var << endl; }

template<typename T, typename... Args>
void _bug(ostream &os, T const &var, Args const &... args) {
    os << var << ' ';
    _bug(os, args...);
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 2e5+3;

int n;
ii a[maxn];
int st[8*maxn], lazy[8*maxn];

void push(int id, int l, int r) {
    if (lazy[id] == oo) return;
    st[id] = min(st[id], lazy[id]);
    if (l < r) {
        lazy[2*id] = min(lazy[2*id], lazy[id]);
        lazy[2*id+1] = min(lazy[2*id+1], lazy[id]);
    }
    lazy[id] = oo;
}

void update(int id, int l, int r, int ql, int qr, int val) {
    push(id, l, r);
    if (ql > r || qr < l) return;
    if (ql <= l && qr >= r) {
        lazy[id] = min(lazy[id], val);
        push(id, l, r);
        return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, ql, qr, val);
    update(2*id+1, mid+1, r, ql, qr, val);
    st[id] = min(st[2*id], st[2*id+1]);
}

int query(int id, int l, int r, int pos) {
    push(id, l, r);
    if (pos > r || pos < l) return oo;
    if (l == r) return st[id];
    int mid = (l+r)/2;
    return min(query(2*id, l, mid, pos), query(2*id+1, mid+1, r, pos));
}

#define multi_test 1
void _main() {
    cin >> n;
    vector<int> b;

    fto (i, 1, n) {
        cin >> a[i].ff >> a[i].ss;
        b.push_back(a[i].ff);
        b.push_back(a[i].ss);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    fto (i, 1, n) {
        a[i].ff = lower_bound(all(b), a[i].ff) - b.begin()+1;
        a[i].ss = lower_bound(all(b), a[i].ss) - b.begin()+1;
    }

    fto (i, 1, 8*n) st[i] = lazy[i] = oo;
    sort(a+1, a+1+n);

    int cnt = 0;
    oss<ii> s;

    int ans = 0;
    fto (i, 1, n) {
        int pos = query(1, 1, 2*n, a[i].ff);
        if (pos == oo) ans = max(ans, 1);
        else ans = max(ans, (int)(i - s.order_of_key(ii(pos, 0))));
        update(1, 1, 2*n, a[i].ff, a[i].ss, a[i].ff);
        s.insert({a[i].ss, ++cnt});
    }

    bug(n - ans);
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