#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define forit(it, l, r) for(auto it = (l); it != (r); ++it)
#define fit(it, var) forit(it, (var).begin(), (var).end())
#define frit(it, var) forit(it, (var).rbegin(), (var).rend())

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

int n, q;
int a[maxn], b[maxn];
vector<int> f[4*maxn];

void build(int id, int l, int r, int *al, int *ar) {
	int mid = (l + r)/2;
	auto comp = [&](int x) { return x <= mid;};
	f[id].reserve(ar - al); f[id].pb(0);
	forit (it, al, ar) {
		f[id].pb(f[id].back() + comp(*it));
	}
	if (l == r) return;
	int *am = stable_partition(al, ar, comp);
	build(2*id, l, mid, al, am);
	build(2*id+1, mid+1, r, am, ar);
}

int query(int id, int l, int r, int ql, int qr, int k) {
	if (l == r) return l;
	int mid = (l+r)/2;
	int cnt = f[id][qr] - f[id][ql];
	if (cnt >= k) return query(2*id, l, mid, f[id][ql], f[id][qr], k);
	return query(2*id+1, mid+1, r, ql - f[id][ql], qr - f[id][qr], k - cnt);
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	scanf("%d%d", &n, &q);

	fto (i, 1, n) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	sort(b + 1, b + 1 + n);
	int N = unique(b + 1, b + 1 + n) - b - 1;

	fto (i, 1, n) a[i] = lower_bound(b + 1, b + 1 + N, a[i]) - b;

	build(1, 1, N, a + 1, a + 1 + n);

	int u, v, k;
	fto (i, 1, q) {
		scanf("%d%d%d", &u, &v, &k);
		printf("%d\n", b[query(1, 1, N, u-1, v, k)]);
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}