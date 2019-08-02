#include <bits/stdc++.h>
 
using namespace std;
 
#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(var, it) for (auto it = (var).begin(); it != (var).end(); ++it)
#define frit(var, it) for (auto it = (var).rbegin(); it != (var).rend(); ++it)
 
#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl
 
#define bc __builtin_popcountll
#define onb(x, bit) (x & (1 << bit))
#define gcd __gcd
#define y1 ansdj
 
#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())
 
template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}
 
char* sfm(const char *fmt, ...) {
	static char res[256];va_list args;va_start(args, fmt);vsnprintf(res, 100, fmt, args);va_end(args);return res;
}
 
char __c;
template<class T> bool scan(T &val) {
    for (__c = getchar(); __c != '-' && __c != EOF && (__c < '0' || __c > '9'); __c = getchar()); if (__c == EOF) return 0;
    bool neg = (__c == '-'); if (neg) val = 0; else val = __c - '0';
    for (__c = getchar(); __c >= '0' && __c <= '9'; __c = getchar()) val = val*10 + __c - '0';
    if (neg) val = -val; return 1;
}
bool scan(char &c) { c = getchar(); return c != EOF; }
bool scan(string &s) {
	s = ""; for (__c = getchar(); __c == ' ' || __c == '\n'; __c = getchar()); if (__c == EOF) return 0;
	s += __c; for (__c = getchar(); __c != ' ' && __c != '\n' && __c != EOF; __c = getchar()) s += __c; return 1;
}
template<class T, class... Args> bool scan(T &val, Args&... args) { scan(val); return scan(args...); }
 
double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003
 
int n, B;
pair<int, ii> a[maxn];
pair<ll, ll> f[4*maxn];
ll b[maxn], c[maxn];
 
ll get(pair<ll, ll> &line, int x) {
	return line.x*x + line.y;
}
 
ll query(int id, int l, int r, int pos) {
	if (l > pos || r < pos) return -OO;
	ll res = get(f[id], pos);
	if (l == r) return res;
	int mid = (l+r)/2;
	return max(res, max(query(2*id, l, mid, pos), query(2*id+1, mid+1, r, pos)));
}
 
void update(int id, int l, int r, pair<ll, ll> &line) {
	bool lval = get(f[id], l) >= get(line, l);
	bool rval = get(f[id], r) >= get(line, r);
	if (lval && rval) return;
	if (!lval && !rval) {
		f[id] = line;
		return;
	}
	int mid = (l+r)/2;
	bool mval = get(f[id], mid) >= get(line, mid);
	if (lval && mval) {
		update(2*id+1, mid+1, r, line);
		return;
	}
	if (!lval && !mval) {
		update(2*id+1, mid+1, r, f[id]);
		f[id] = line;
		return;
	}
	mval = get(f[id], mid+1) >= get(line, mid+1);
	if (mval && rval) {
		update(2*id, l, mid, line);
		return;
	}
	if (!mval && !rval) {
		update(2*id, l, mid, f[id]);
		f[id] = line;
		return;
	}
	update(2*id, l, mid, line);
	update(2*id+1, mid+1, r, line);
}
 
int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	scan(n, B);
	fto (i, 1, n) {
		scan(a[i].x, a[i].y.x, a[i].y.y);
	}
	sort(a + 1, a + 1 + n);
 
	ll ans;
	fto (i, 1, n) {
		b[i] = b[i-1] + a[i].y.y;
		c[i] = c[i-1] + a[i].y.x + (ll)a[i].x * a[i].y.y;
		ans = c[i] - b[i]*a[i].x - B + max(0ll, query(1, 1, 1e5, a[i].x));
		pair<ll, ll> line(b[i], ans - c[i]);
		update(1, 1, 1e5, line);
	}
 
	cout << ans << endl;
 
	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
} 