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
int const maxn = 2e5+3;

int n, q;
int a[maxn];
ll st[4*maxn], lazy[4*maxn];

void init(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    init(2*id, l, mid); init(2*id+1, mid+1, r);
    st[id] = st[2*id] + st[2*id+1];
}

void push(int id, int l, int r) {
    if (!lazy[id]) return;
    if (lazy[id] < 0) st[id] = (r-l+1) * -lazy[id];
    else st[id] += (r-l+1) * lazy[id];
    if (l < r) {
        if (lazy[id] < 0) lazy[2*id] = lazy[2*id+1] = lazy[id];
        else {
            lazy[2*id] += lazy[id] * (lazy[2*id] < 0 ? -1 : 1);
            lazy[2*id+1] += lazy[id] * (lazy[2*id+1] < 0 ? -1 : 1);
        }
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int ql, int qr, int val) {
    push(id, l, r);
    if (qr < l || ql > r) return;
    if (ql <= l && qr >= r) {
        if (val < 0) lazy[id] = val;
        else lazy[id] += val * (lazy[id] < 0 ? -1 : 1);
        push(id, l, r);
        return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, ql, qr, val);
    update(2*id+1, mid+1, r, ql, qr, val);
    st[id] = st[2*id] + st[2*id+1];
}

ll query(int id, int l, int r, int ql, int qr) {
    push(id, l, r);
    if (qr < l || ql > r) return 0;
    if (ql <= l && qr >= r) return st[id];
    int mid = (l+r)/2;
    return query(2*id, l, mid, ql, qr) + query(2*id+1, mid+1, r, ql, qr);
}

#define multi_test 0
void _main() {
    cin >> n >> q;
    fto (i, 1, n) cin >> a[i];
    init(1, 1, n);
    while (q--) {
        int t; cin >> t;
        if (t == 3) {
            int l, r; cin >> l >> r;
            bug(query(1, 1, n, l, r));
        } else {
            int l, r, v; cin >> l >> r >> v;
            if (t == 2) v = -v;
            update(1, 1, n, l, r, v);
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