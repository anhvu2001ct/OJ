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
#define maxn 200003

int n, k, result = oo;
int p[maxn], depth[maxn], size[maxn], cd[maxn];
ll dt[maxn];
bool deleted[maxn];
int f[maxn][18];
map<int, int> ans[maxn];
vector<int> g[maxn], b[maxn];
vector<ii> a[maxn];

void dfs0(int u) {
	fto (i, 1, 17) f[u][i] = f[f[u][i-1]][i-1];
	fto1 (i, 0, glen(a[u])) {
		int next = a[u][i].ff;
		if (next == f[u][0]) continue;
		f[next][0] = u;
		depth[next] = depth[u] + 1;
		dt[next] = dt[u] + a[u][i].ss;
		dfs0(next);
	}
}

int dfs(int u) {
	size[u] = 1;
	fto1 (i, 0, glen(a[u])) {
		int next = a[u][i].ff;
		if (next == p[u] || deleted[next]) continue;
		p[next] = u;
		size[u] += dfs(next);
	}
	return size[u];
}

int dfs(int u, int total) {
	fto1 (i, 0, glen(a[u])) {
		int next = a[u][i].ff;
		if (next == p[u] || deleted[next]) continue;
		if (size[next] > total/2) return dfs(next, total);
	}

	deleted[u] = 1;
	fto1 (i, 0, glen(a[u])) {
		int next = a[u][i].ff;
		if (deleted[next]) continue;
		p[next] = 0;
		int sub = dfs(next, dfs(next));
		g[u].pb(sub);
		cd[sub] = u;
	}
	return u;
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	int diff = depth[u] - depth[v];
	fto (i, 0, 17) if (diff & (1 << i)) u = f[u][i];
	if (u == v) return u;
	fdto (i, 17, 0) if (f[u][i] != f[v][i]) {
		u = f[u][i];
		v = f[v][i];
	}
	return f[u][0];
}

pair<ll, int> dist(int u, int v) {
	int lca = LCA(u, v);
	return pair<ll, int>(dt[u] + dt[v] - 2*dt[lca], depth[u] + depth[v] - 2*depth[lca]);
}

void solve(int u) {
	fto1 (i, 0, glen(g[u])) {
		int next = g[u][i];
		solve(next);
		pair<ll, int> distance;
		ll total;

		if (i) fto1 (i, 0, glen(b[next])) {
			int v = b[next][i];
			distance = dist(u, v);
			if (distance.ff <= k && ans[u].count(k - distance.ff)) result = min(result, ans[u][k - distance.ff] + distance.ss);
		}

		fto1 (i, 0, glen(b[next])) {
			int v = b[next][i];
			b[u].pb(v);
			distance = dist(u, v);
			if (distance.ff <= k) {
				if (!ans[u].count(distance.ff)) ans[u][distance.ff] = distance.ss;
				else ans[u][distance.ff] = min(ans[u][distance.ff], distance.ss);
			}
		}
	}
	b[u].pb(u);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	scanf("%d%d", &n, &k);

	int u, v, w;

	fto1 (i, 1, n) {
		scanf("%d%d%d", &u, &v, &w);
		++u; ++v;
		a[u].pb(ii(v, w));
		a[v].pb(ii(u, w));
	}

	dfs0(1);
	int root = dfs(1, dfs(1));
	solve(root);

	fto (i, 1, n) if (ans[i].count(k)) result = min(result, ans[i][k]);

	printf("%d\n", result == oo ? -1 : result);

	return 0;
}