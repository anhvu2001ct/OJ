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
#define maxn 100003

int n, q;
int p[maxn], size[maxn], deleted[maxn], cd[maxn], depth[maxn], ans[maxn];
int f[maxn][17];
vector<int> a[maxn];

void dfs0(int u) {
	fto (i, 1, 16) f[u][i] = f[f[u][i-1]][i-1];
	fto1 (i, 0, glen(a[u])) {
		int v = a[u][i];
		if (v == f[u][0]) continue;
		f[v][0] = u;
		depth[v] = depth[u] + 1;
		dfs0(v);
	}
}

int dfs(int u) {
	size[u] = 1;
	fto1 (i, 0, glen(a[u])) {
		int v = a[u][i];
		if (v == p[u] || deleted[v]) continue;
		p[v] = u;
		size[u] += dfs(v);
	}
	return size[u];
}

int dfs(int u, int total) {
	fto1 (i, 0, glen(a[u])) {
		int v = a[u][i];
		if (v == p[u] || deleted[v]) continue;
		if (size[v] > total/2) return dfs(v, total);
	}

	deleted[u] = 1;
	fto1 (i, 0, glen(a[u])) {
		int v = a[u][i];
		if (deleted[v]) continue;
		p[v] = 0;
		cd[dfs(v, dfs(v))] = u;
	}
	return u;
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	fto (i, 0, 16) if ((diff >> i) & 1) u = f[u][i];
	if (u == v) return u;
	fdto (i, 16, 0) {
		if (f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];
}

int dist(int u, int v) {
	return depth[u] + depth[v] - 2*depth[LCA(u, v)];
}

void update(int u) {
	int x = u;
	while (u) {
		ans[u] = min(ans[u], dist(u, x));
		u = cd[u];
	}
}

int get(int u) {
	int x = u, res = oo;
	while (u) {
		res = min(res, ans[u] + dist(u, x));
		u = cd[u];
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	scanf("%d%d", &n, &q);

	int u, v;

	fto1 (i, 1, n) {
		scanf("%d%d", &u, &v);
		a[u].pb(v);
		a[v].pb(u);
	}

	dfs0(1);
	dfs(1, dfs(1));

	fto (i, 1, n) ans[i] = oo;
	update(1);

	while (q--) {
		scanf("%d%d", &u, &v);
		if (u == 1) update(v);
		else printf("%d\n", get(v));
	}

	return 0;
}