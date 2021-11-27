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
int const maxn = 1e3+3;

int n, q;
int a[maxn][maxn];
int st[4*maxn][4*maxn];

void buildy(int rid, int rl, int rr, int id, int l, int r) {
    if (l == r) {
        if (rl == rr) st[rid][id] = a[l][rl];
        else st[rid][id] = st[2*rid][id] + st[2*rid+1][id];
        return;
    }
    int mid = (l+r)/2;
    buildy(rid, rl, rr, 2*id, l, mid);
    buildy(rid, rl, rr, 2*id+1, mid+1, r);
    st[rid][id] = st[rid][2*id] + st[rid][2*id+1];
}

void buildx(int id, int l, int r) {
    if (l == r) {
        buildy(id, l, r, 1, 1, n);
        return;
    }
    int mid = (l+r)/2;
    buildx(2*id, l, mid);
    buildx(2*id+1, mid+1, r);
    buildy(id, l, r, 1, 1, n);
}

int queryy(int rid, int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0;
    if (ql <= l && qr >= r) return st[rid][id];
    int mid = (l+r)/2;
    return queryy(rid, 2*id, l, mid, ql, qr) + queryy(rid, 2*id+1, mid+1, r, ql, qr);
}

int queryx(int id, int l, int r, int qy1, int qx1, int qy2, int qx2) {
    if (r < qx1 || l > qx2) return 0;
    if (qx1 <= l && qx2 >= r) return queryy(id, 1, 1, n, qy1, qy2);
    int mid = (l+r)/2;
    return queryx(2*id, l, mid, qy1, qx1, qy2, qx2) + queryx(2*id+1, mid+1, r, qy1, qx1, qy2, qx2);
}

void updatey(int rid, int rl, int rr, int id, int l, int r, int y) {
    if (y < l || y > r) return;
    if (l == r) {
        if (rl == rr) st[rid][id] ^= 1;
        else st[rid][id] = st[2*rid][id] + st[2*rid+1][id];
        return;
    }
    int mid = (l+r)/2;
    updatey(rid, rl, rr, 2*id, l, mid, y);
    updatey(rid, rl, rr, 2*id+1, mid+1, r, y);
    st[rid][id] = st[rid][2*id] + st[rid][2*id+1];
}

void updatex(int id, int l, int r, int y, int x) {
    if (x < l || x > r) return;
    if (l == r) {
        updatey(id, l, r, 1, 1, n, y);
        return;
    }
    int mid = (l+r)/2;
    updatex(2*id, l, mid, y, x);
    updatex(2*id+1, mid+1, r, y, x);
    updatey(id, l, r, 1, 1, n, y);
}

#define multi_test 0
void _main() {
    cin >> n >> q;
    string s;
    fto (i, 1, n) {
        cin >> s;
        fto1 (j, 0, n) {
            a[i][j+1] = (s[j] == '*');
        }
    }
    buildx(1, 1, n);
    while (q--) {
        int t; cin >> t;
        if (t == 2) {
            int x1, y1, x2, y2;
            cin >> y1 >> x1 >> y2 >> x2;
            bug(queryx(1, 1, n, y1, x1, y2, x2));
        } else {
            int x, y; cin >> y >> x;
            updatex(1, 1, n, y, x);
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