#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = s; i <= e; ++i)
#define fto1(i, s, e) for(int i = s; i < e; ++i)
#define fdto(i, s, e) for(int i = s; i >= e; --i)
#define fdto1(i, s, e) for(int i = s; i > e; --i)
#define fit(var, it) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for(__typeof(var.rbegin()) it = var.rbegin(); it != var.rend(); ++it)

#define newl '\n'
#define Vname(var) #var
#define debugt cerr << 0.001*clock() << newl
#define debug1(x, i) cout << Vname(x) << '[' << i << "] = " << x[i] << newl
#define debug(v, l, r) fto(_i, l, r) debug1(v, _i)
#define debug2(x, i, j) cout << Vname(x) << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define debug3(x, i, j, k) cout << Vname(x) << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.first << ", " << v.second << ')';
}

#define ll long long
#define ii pair<int, int>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define glen(v) ((int) (v).size())

#define eps 1e-15
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 50003

struct data {
	int v, w;
	bool fw;
};

int n, m, s, t;
ll ans;
int c[maxn], lvl[maxn], p[maxn];
vector<int> a[maxn];
vector<data> edge;

void addEdge(int u, int v, int w) {
	a[u].pb(glen(edge));
	edge.pb({v, w, 1});
	a[v].pb(glen(edge));
	edge.pb({u, 0, 0});
}

bool bfs() {
	queue<int> q;
	q.push(s);
	fto (i, 1, t) lvl[i] = -1;
	lvl[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		fto1 (i, 0, glen(a[u])) {
			int v = edge[a[u][i]].v;
			int w = edge[a[u][i]].w;
			if (lvl[v] == -1 && w) {
				lvl[v] = lvl[u]+1;
				q.push(v);
			}
		}
	}
	return lvl[t] > -1;
}

int dfs(int u, int flow) {
	if (u == t) return flow;
	fto1 (i, 0, glen(a[u])) {
		int v = edge[a[u][i]].v;
		int &w = edge[a[u][i]].w;
		if (lvl[v] == lvl[u]+1 && w) {
			int x = dfs(v, min(flow, w));
			if (x) {
				w -= x;
				edge[a[u][i]^1].w += x;
				return x;
			}
		}
	}
	return 0;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d%d", &n, &m);
	s = n+m+1;
	t = s+1;

	fto (i, 1, n) {
		scanf("%d", &c[i]);
		addEdge(i, t, c[i]);
	}

	int u, v, w;
	fto (i, 1, m) {
		scanf("%d%d%d", &u, &v, &w);
		addEdge(s, n+i, w);
		addEdge(n+i, u, oo);
		addEdge(n+i, v, oo);
		ans += w;
	}

	int flow;
	while (bfs()) {
		while (flow = dfs(s, oo)) ans -= flow;
		fto (i, 1, t) p[u] = 0;
	}

	cout << ans << newl;

	return 0;
}