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
#define maxn 1000003
 
struct data {
	pair<ll, ll> line;
	data *left, *right;
};
 
int n;
pair<pair<ll, int>, ll> a[maxn];
vector<int> s;
 
ll get(pair<ll, ll> &line, int x) {
	return -line.x*x + line.y;
}
 
void extend(data *root) {
	if (root->left) return;
	root->left = new data({{0ll, 0ll}, nullptr, nullptr});
	root->right = new data({{0ll, 0ll}, nullptr, nullptr});
}
 
ll query(data *root, int l, int r, int pos) {
	if (l > pos || r < pos) return -OO;
	ll res = get(root->line, s[pos]);
	if (l == r) return res;
	int mid = (l+r)/2;
	extend(root);
	return max(res, max(query(root->left, l, mid, pos), query(root->right, mid+1, r, pos)));
}
 
void update(data *root, int l, int r, pair<ll, ll> &line) {
	bool lval = get(root->line, s[l]) >= get(line, s[l]);
	bool rval = get(root->line, s[r]) >= get(line, s[r]);
	if (lval && rval) return;
	if (!lval && !rval) {
		root->line = line;
		return;
	}
	int mid = (l+r)/2;
	extend(root);
	bool mval = get(root->line, s[mid]) >= get(line, s[mid]);
	if (lval && mval) {
		update(root->right, mid+1, r, line);
		return;
	}
	if (!lval && !mval) {
		update(root->right, mid+1, r, root->line);
		root->line = line;
		return;
	}
	mval = get(root->line, s[mid+1]) >= get(line, s[mid+1]);
	if (mval && rval) {
		update(root->left, l, mid, line);
		return;
	}
	if (!mval && !rval) {
		update(root->left, l, mid, root->line);
		root->line = line;
		return;
	}
	update(root->left, l, mid, line);
	update(root->right, mid+1, r, line);
}
 
int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	scanf("%d", &n);
	fto (i, 1, n) {
		scanf("%lld%d%lld", &a[i].x.x, &a[i].x.y, &a[i].y);
		s.pb(a[i].x.y);
	}
	sort(a + 1, a + 1 + n);
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	data *root = new data({{0ll, 0ll}, nullptr, nullptr});
 
	ll cur, ans = 0;
	fto (i, 1, n) {
		int pos = lower_bound(s.begin(), s.end(), a[i].x.y) - s.begin();
		cur = a[i].x.x * a[i].x.y - a[i].y + query(root, 0, sz(s)-1, pos);
		pair<ll, ll> line(a[i].x.x, cur);
		update(root, 0, sz(s)-1, line);
		ans = max(ans, cur);
	}
 
	cout << ans << endl;
	
	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}