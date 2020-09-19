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
#define maxn 100003

int n;
int a[maxn], b[maxn];
pair<ll, ll> f[4*maxn];

ll get(pair<ll, ll> &line, int x) {
	return line.x*x + line.y;
}

void update(int id, int l, int r, pair<ll, ll> &line) {
	bool lval = get(f[id], a[l]) <= get(line, a[l]);
	bool rval = get(f[id], a[r]) <= get(line, a[r]);
	if (lval && rval) return;
	if (!lval && !rval) {
		f[id] = line;
		return;
	}
	int mid = (l+r)/2;
	bool mval = get(f[id], a[mid]) <= get(line, a[mid]);
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
	ll res = get(f[id], a[pos]);
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

	fto (i, 1, n) {
		scanf("%d", &a[i]);
	}

	fto (i, 1, n) {
		scanf("%d", &b[i]);
	}

	n <<= 2;
	fto (i, 1, n) f[i].y = OO;
	n >>= 2;

	pair<ll, ll> line(b[1], 0);
	update(1, 1, n, line);

	ll ans;
	fto (i, 2, n) {
		ans = query(1, 1, n, i);
		pair<ll, ll> line(b[i], ans);
		update(1, 1, n, line);
	}

	cout << ans << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}