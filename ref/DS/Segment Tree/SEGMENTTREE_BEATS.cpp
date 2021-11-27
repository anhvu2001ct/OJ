#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
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
#define bugn(...) _bugn(#__VA_ARGS__, __VA_ARGS__)
#define buga(a, s, e) cout << '{'; fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

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

template<typename... Args>
void _bugn(string const &s, Args const &... args) {
    auto split = [](string const &s, string const &delim) {
        int next, pos = 0;
        vector<string> res;
        while (1) {
            next = s.find(delim, pos);
            if (next == string::npos) break;
            res.push_back(s.substr(pos, next-pos));
            pos = next+sz(delim);
        }
        res.push_back(s.substr(pos));
        return res;
    };

    ostringstream os; _bug(os, args...);
    string tmp = os.str(); tmp.pop_back(); 
    vector<string> v1 = split(s, ", "), v2 = split(tmp, " ");
    fto1 (i, 0, sz(v1)) cout << '[' << v1[i] << ": " << v2[i] << "]" << " \n"[i == sz(v1)-1];
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e6+3;

struct data {
    ll sum;
    int fnum, fmax, smax;
};

int n, m;
int a[maxn];
data st[4*maxn];

data merge(data &l, data &r) {
    data res;
    res.sum = l.sum + r.sum;
    if (l.fmax == r.fmax) {
        res.fmax = l.fmax;
        res.fnum = l.fnum + r.fnum;
        res.smax = max(l.smax, r.smax);
    } else {
        bool tmp = l.fmax > r.fmax;
        if (!tmp) swap(l, r);
        res.fmax = l.fmax;
        res.fnum = l.fnum;
        res.smax = max(l.smax, r.fmax);
        if (!tmp) swap(l, r);
    }
    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = {a[l], 1, a[l], -oo};
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    st[id] = merge(st[2*id], st[2*id+1]);
}

void addtag(int id, int x) {
    st[id].sum -= (ll)(st[id].fmax - x) * st[id].fnum;
    st[id].fmax = x;
}

void pushdown(int id, int l, int r) {
    if (st[id].fmax < st[2*id].fmax) addtag(2*id, st[id].fmax);
    if (st[id].fmax < st[2*id+1].fmax) addtag(2*id+1, st[id].fmax);
}

void update(int id, int l, int r, int ql, int qr, int x) {
    if (ql > r || qr < l || st[id].fmax <= x) return;
    if (ql <= l && qr >= r && st[id].smax < x) {
        addtag(id, x);
        return;
    }
    pushdown(id, l, r);
    int mid = (l+r)/2;
    update(2*id, l, mid, ql, qr, x);
    update(2*id+1, mid+1, r, ql, qr, x);
    st[id] = merge(st[2*id], st[2*id+1]);
}

ll query_sum(int id, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) return st[id].sum;
    pushdown(id, l, r);
    int mid = (l+r)/2;
    return query_sum(2*id, l, mid, ql, qr) + query_sum(2*id+1, mid+1, r, ql, qr);
}

int query_max(int id, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return -oo;
    if (ql <= l && qr >= r) return st[id].fmax;
    pushdown(id, l, r);
    int mid = (l+r)/2;
    return max(query_max(2*id, l, mid, ql, qr), query_max(2*id+1, mid+1, r, ql, qr));
}

#define multi_test 1
void _main() {
    cin >> n >> m;
    fto (i, 1, n) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else {
            int l, r; cin >> l >> r;
            if (t == 1) bug(query_max(1, 1, n, l, r));
            else bug(query_sum(1, 1, n, l, r));
        }
    }
}

int main() {
    #ifdef KITTENS
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    if (multi_test) cin >> t;
    while (t--) {
        _main();
    }

    #ifdef KITTENS
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}