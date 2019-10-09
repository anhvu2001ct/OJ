#include <bits/stdc++.h>
 
using namespace std;
 
#define fto(i, s, e) for (int i = s; i <= e; ++i)
#define fto1(i, s, e) for (int i = s; i < e; ++i)
#define fdto(i, s, e) for (int i = s; i >= e; --i)
#define fdto1(i, s, e) for (int i = s; i > e; --i)
#define fit(var, it) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for (__typeof(var.rbegin()) it = var.rbegin(); it != var.rend(); ++it)
 
#define newl '\n'
#define Vname(var) #var
#define debugt cerr << 0.001*clock() << newl
#define debug(x) cout << Vname(x) << " = " << x << newl
#define debug1(x, i) cout << Vname(x) << '[' << i << ']' << " = " << x[i] << newl
#define debug2(x, i, j) cout << Vname(x) << '[' << i << ']' << '[' << j << ']' << " = " << x[i][j] << newl
#define debug3(x, i, j, k) cout << Vname(x) << '[' << i << ']' << '[' << j << ']' << '[' << k << ']' << " = " << x[i][j][k] << newl
#define debuga(x, s, e) cout << Vname(x) << " = "; _debuga(x, s, e); cout << newl
 
#define ll long long
#define ii pair<int, int>
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define glen(v) ((int) (v).size())
 
template<typename T> void _debuga(T const &v, int s, int e) {
	cout << '[' << (e - s + 1) << ", " << s << "->" << e << "] {"; fto (i, s, e) { cout << v[i]; if (i < e) cout << ", "; } cout << '}';
}
 
template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}
 
template<typename T> ostream& operator<< (ostream &os, vector<T> const &v) {
	os << '[' << glen(v) << "] {"; fto1 (i, 0, glen(v)) { os << v[i]; if (i < glen(v) - 1) os << ", "; } return os << '}';
}
 
#define eps 1e-18
#define oo 1000000009
#define mod 1000000007
#define maxn 50003
 
int n, m, l, r, curL, curR, N;
int a[maxn], ans[maxn], cnt[maxn], f[maxn];
 
struct Query {
	ii ff, ss;
	int pos;
};

Query q[maxn];

void add(int idx, int x) {
	if (!idx) return;
	for (; idx <= n; idx += idx & -idx) f[idx] += x;
}

int get(int idx) {
	int res = 0;
	for (; idx; idx -= idx & -idx) res += f[idx];
	return res;
}

void add(int X) {
	if (!X) return;
	add(cnt[X], -1);
	++cnt[X];
	add(cnt[X], 1);
}

void remove(int X) {
	if (!X) return;
	add(cnt[X], -1);
	--cnt[X];
	add(cnt[X], 1);
}
 
int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	scanf("%d", &n);

	vector<int> b;
	fto (i, 1, n) {
		scanf("%d", &a[i]);
		b.pb(a[i]);
	}

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	fto (i, 1, n) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

	scanf("%d", &m);
 
	fto (i, 1, m) {
		scanf("%d%d", &q[i].ff.ff, &q[i].ff.ss);
		--q[i].ff.ff; --q[i].ff.ss;
		scanf("%d%d", &q[i].ss.ff, &q[i].ss.ss);
		q[i].pos = i;
	}
 
	N = (int)sqrt(n);

	int tmpL;
	sort(q + 1, q + 1 + m, [&](Query const &l, Query const &r) {
		tmpL = l.ff.ff/N;
		if (tmpL != r.ff.ff/N) return l.ff.ff < r.ff.ff;
		return (tmpL%2 == 0) ? (l.ff.ss < r.ff.ss) : (l.ff.ss > r.ff.ss);
	});

	fto (i, 1, m) {
		l = q[i].ff.ff+1;
		r = q[i].ff.ss+1;
 
		while (curR < r) {
			++curR;
			add(a[curR]);
		}
		while (curL < l) {
			remove(a[curL]);
			++curL;
		}
		while (curL > l) {
			--curL;
			add(a[curL]);
		}
		while (curR > r) {
			remove(a[curR]);
			--curR;
		}
 
		ans[q[i].pos] = get(q[i].ss.ss) - get(q[i].ss.ff-1);
	}

	fto (i, 1, m) {
		printf("%d\n", ans[i]);
	}

	return 0;
}