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
int const maxn = 1e5+3;

int n, m;
int a[maxn];
bool lazy[4*maxn];
pair<ll, ii> st[4*maxn];

pair<ll, ii> merge(pair<ll, ii> &l, pair<ll, ii> &r) {
    return {l.ff + r.ff, {max(l.ss.ff, r.ss.ff), min(l.ss.ss, r.ss.ss)}};
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = {a[l], {a[l], a[l]}};
        return;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid); build(2*id+1, mid+1, r);
    st[id] = merge(st[2*id], st[2*id+1]);
}

void addtag(int id, int l, int r, int val) {
    lazy[id] = 1;
    st[id].ss.ff = st[id].ss.ss = val;
    st[id].ff = val * (r-l+1);
}

void pushdown(int id, int l, int r) {
    if (!lazy[id]) return;
    int mid = (l+r)/2;
    addtag(2*id, l, mid, st[id].ss.ff);
    addtag(2*id+1, mid+1, r, st[id].ss.ff);
    lazy[id] = 0;
}

void update1(int id, int l, int r, int ql, int qr, int mod) {
    if (ql > r || qr < l || st[id].ss.ff < mod) return;
    if (l >= ql && r <= qr && st[id].ss.ff == st[id].ss.ss) {
        addtag(id, l, r, st[id].ss.ff % mod);
        return;
    }
    pushdown(id, l, r);
    int mid = (l+r)/2;
    update1(2*id, l, mid, ql, qr, mod);
    update1(2*id+1, mid+1, r, ql, qr, mod);
    st[id] = merge(st[2*id], st[2*id+1]);
}

void update2(int id, int l, int r, int k, int x) {
    if (k > r || k < l) return;
    if (l == r) {
        st[id] = {x, {x, x}};
        return;
    }
    pushdown(id, l, r);
    int mid = (l+r)/2;
    update2(2*id, l, mid, k, x);
    update2(2*id+1, mid+1, r, k, x);
    st[id] = merge(st[2*id], st[2*id+1]);
}

ll query(int id, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) return st[id].ff;
    pushdown(id, l, r);
    int mid = (l+r)/2;
    return query(2*id, l, mid, ql, qr) + query(2*id+1, mid+1, r, ql, qr);
}

#define multi_test 0
void _main() {
    cin >> n >> m;
    fto (i, 1, n) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            bug(query(1, 1, n, l, r));
        } else if (t == 2) {
            int l, r, x; cin >> l >> r >> x;
            update1(1, 1, n, l, r, x);
        } else {
            int k, x; cin >> k >> x;
            update2(1, 1, n, k, x);
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