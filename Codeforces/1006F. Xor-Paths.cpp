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
#define debug1(x, i) cout << Vname(x) << '[' << i << ']' << " = " << x[i] << newl
#define debug2(x, i, j) cout << Vname(x) << '[' << i << ']' << '[' << j << ']' << " = " << x[i][j] << newl

template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.first << ", " << v.second << ')';
}

#define ll long long
#define ii pair<int, int>

#define ff first
#define ss second
#define pb push_back
#define glen(v) ((int) (v).size())

#define eps 1e-15
#define oo 1000000007
#define OO 1000000000000000007LL
#define maxn 23

int n, m;
ll k, cur, ans;
ll a[maxn][maxn];
map<ll, ll> cnt[maxn];

void dfs(int x, int y, int tmp) {
	cur ^= a[x][y];
	if (tmp == n) {
		++cnt[x][cur];
		cur ^= a[x][y];
		return;
	}
	++tmp;
	if (x < n) dfs(x+1, y, tmp);
	if (y < m) dfs(x, y+1, tmp);
	cur ^= a[x][y];
}

void rdfs(int x, int y, int tmp) {
	if (tmp == m) {
		if (cnt[x].count(cur^k)) ans += cnt[x][cur^k];
		return;
	}
	cur ^= a[x][y];
	++tmp;
	if (x > 1) rdfs(x-1, y, tmp);
	if (y > 1) rdfs(x, y-1, tmp);
	cur ^= a[x][y];
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	scanf("%d%d%I64d", &n, &m, &k);

	fto (i, 1, n) fto (j, 1, m) scanf("%I64d", &a[i][j]);

	dfs(1, 1, 1);
	rdfs(n, m, 1);

	printf("%I64d\n", ans);

	return 0;
}