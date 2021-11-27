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

int n;
ll a[maxn], sum1[maxn], sum2[maxn];
pll st[4*maxn];

ll get(pll const &line, ll x) {
	return line.ff*x + line.ss;
}

void update(int id, int l, int r, pll const &line) {
	bool lval = get(st[id], a[l]) >= get(line, a[l]);
	bool rval = get(st[id], a[r]) >= get(line, a[r]);
	if (lval && rval) return;
	if (!lval && !rval) {
		st[id] = line;
		return;
	}
	int mid = (l+r)/2;
	bool mval = get(st[id], a[mid]) >= get(line, a[mid]);
	if (lval && mval) {
		update(2*id+1, mid+1, r, line);
		return;
	}
	if (!lval && !mval) {
		update(2*id+1, mid+1, r, st[id]);
		st[id] = line;
		return;
	}
	if (mval && rval) {
		update(2*id, l, mid, line);
		return;
	}
	if (!mval && !rval) {
		update(2*id, l, mid, st[id]);
		st[id] = line;
		return;
	}
}

ll get(int id, int l, int r, int pos) {
	if (pos > r || pos < l) return -OO;
	ll res = get(st[id], a[pos]);
	if (l == r) return res;
	int mid = (l+r)/2;
	return max(res, max(get(2*id, l, mid, pos), get(2*id+1, mid+1, r, pos)));
}

#define multi_test 0
void _main() {
    cin >> n;
	fto (i, 1, n) {
		cin >> a[i];
		sum1[i] = sum1[i-1] + a[i];
		sum2[i] = sum2[i-1] + a[i]*i;
		a[i] = sum1[i];
	}
	sort(a+1, a+1+n);
	ll ans = 0;
	fto (i, 1, n) {
		ans = max(ans, get(1, 1, n, lower_bound(a+1, a+1+n, sum1[i])-a) + sum2[i]);
		update(1, 1, n, {-i, sum1[i]*i - sum2[i]});
	}
	bug(ans);
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