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
#define maxn 30003

int n;
ii a[maxn];
int ans[200003];
int f[4*maxn];

void buildST(int id, int l, int r) {
	f[id] = r-l+1;
	if (l == r) return;
	int m = (l+r)/2;
	buildST(2*id, l, m);
	buildST(2*id+1, m+1, r);
}

void update(int id, int l, int r, int pos) {
	if (l > pos || r < pos) return;
	--f[id];
	if (l == r) return;
	int m = (l+r)/2;
	update(2*id, l, m, pos);
	update(2*id+1, m+1, r, pos);
}

int query(int id, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return f[id];
	int m = (l+r)/2;
	return query(2*id, l, m, ql, qr) + query(2*id+1, m+1, r, ql, qr);
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	scanf("%d", &n);

	buildST(1, 1, n);

	fto (i, 1, n) {
		scanf("%d", &a[i].x);
		a[i].y = i;
	}

	sort(a + 1, a + 1 + n);
	a[n+1] = {oo, oo};

	int q; scanf("%d", &q);

	int u, v, k;
	vector<pair<ii, ii>> b;
	fto (i, 1, q) {
		scanf("%d%d%d", &u, &v, &k);
		b.pb({{k, i}, {u, v}});
	}

	sort(b.begin(), b.end());

	int cur = 0;
	fit (b, it) {
		while (a[cur+1].x <= it->x.x) {
			++cur;
			update(1, 1, n, a[cur].y);
		}
		ans[it->x.y] = query(1, 1, n, it->y.x, it->y.y);
	}

	fto (i, 1, q) printf("%d\n", ans[i]);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}