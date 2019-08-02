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
	static char res[256];va_list args;va_start(args, fmt);vsnprintf(res, 256, fmt, args);va_end(args);return res;
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 1000003

int n;
ii a[maxn];
pair<ll, ll> f[4*maxn];
vector<ii> b;

ll get(pair<ll, ll> &l, int x) {
	return l.x * x + l.y;
}

void update(int id, int l, int r, pair<ll, ll> &line) {
	bool lval = get(f[id], l) <= get(line, l);
	bool rval = get(f[id], r) <= get(line, r);
	if (lval && rval) return;
	if (!lval && !rval) {
		f[id] = line;
		return;
	}
	int mid = (l+r)/2;
	bool mval = get(f[id], mid) <= get(line, mid);
	if (lval && mval) {
		update(2*id+1, mid+1, r, line);
		return;
	}
	if (!lval && !mval) {
		update(2*id+1, mid+1, r, f[id]);
		f[id] = line;
		return;
	}
	mval = get(f[id], mid+1) <= get(line, mid+1);
	if (rval && mval) {
		update(2*id, l, mid, line);
		return;
	}
	if (!rval && !mval) {
		update(2*id, l, mid, f[id]);
		f[id] = line;
		return;
	}
	update(2*id, l, mid, line);
	update(2*id+1, mid+1, r, line);
}

ll query(int id, int l, int r, int pos) {
	if (l > pos || r < pos) return OO;
	ll res = get(f[id], pos);
	if (l == r) return res;
	int mid = (l+r)/2;
	return min(res, min(query(2*id, l, mid, pos), query(2*id+1, mid+1, r, pos)));
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	scanf("%d", &n);

	fto (i, 1, 4e6) f[i].y = OO;

	fto (i, 1, n) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}

	sort(a + 1, a + 1 + n);

	b.pb(a[1]);

	fto (i, 2, n) {
		while (!b.empty() && b.back().y <= a[i].y) b.pop_back();
		b.pb(a[i]);
	}

	ll ans;
	pair<ll, ll> line(b[0].y, 0);
	update(1, 1, 1e6, line);
	fto1 (i, 0, sz(b)) {
		ans = query(1, 1, 1e6, b[i].x);
		if (i == sz(b)-1) continue;
		line = {b[i+1].y, ans};
		update(1, 1, 1e6, line);
	}

	cout << ans << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}