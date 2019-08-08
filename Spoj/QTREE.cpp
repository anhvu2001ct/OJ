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
#define maxn 10003

int n;
vector<ii> a[maxn];
int p[maxn], depth[maxn], cost[maxn];
int heavy[maxn], head[maxn], pos[maxn], chain[maxn];
int edge[maxn], edgeId[maxn];
int st[4*maxn];
char qtype[10];

int dfs(int u) {
	int sz = 1, maxsz = 0;
	fto1 (i, 0, glen(a[u])) {
		int v = a[u][i].ff;
		if (v == p[u]) continue;
		p[v] = u;
		cost[v] = a[u][i].ss;
		depth[v] = depth[u] + 1;
		int vsz = dfs(v);
		if (maxsz < vsz) {
			maxsz = vsz;
			heavy[u] = v;
		}
		sz += vsz;
	}
	return sz;
}

void hld() {
	int cur = -1;
	fto (i, 1, n) {
		if (heavy[p[i]] == i) continue;
		for (int j = i; j; j = heavy[j]) {
			head[j] = i;
			pos[j] = ++cur;
			chain[cur] = edge[cost[j]];
			edgeId[cost[j]] = cur;
		}
	}
}

void buildST(int left, int right, int id) {
	if (left == right) {
		st[id] = chain[left];
		return;
	}

	int mid = (left + right) >> 1;
	buildST(left, mid, 2*id);
	buildST(mid+1, right, 2*id+1);
	st[id] = max(st[2*id], st[2*id+1]);
}

void update(int left, int right, int id, int pos, int value) {
	if (pos < left || pos > right) return;

	if (left == right) {
		st[id] = value;
		return;
	}

	int mid = (left + right) >> 1;
	update(left, mid, 2*id, pos, value);
	update(mid+1, right, 2*id+1, pos, value);
	st[id] = max(st[2*id], st[2*id+1]);
}

int get(int left, int right, int id, int qleft, int qright) {
	if (qleft > right || qright < left) return -oo;
	if (qleft <= left && right <= qright) return st[id];
	int mid = (left + right) >> 1;
	return max(get(left, mid, 2*id, qleft, qright), get(mid+1, right, 2*id+1, qleft, qright));
}

int query(int u, int v) {
	int result = -oo;

	for (; head[u] != head[v]; u = p[head[u]]) {
		if (depth[head[u]] < depth[head[v]]) swap(u, v);
		result = max(result, get(1, n-1, 1, pos[head[u]], pos[u]));
	}

	if (depth[u] < depth[v]) swap(u, v);
	return max(result, get(1, n-1, 1, pos[v]+1, pos[u]));
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	scanf("%*d");

	while (scanf("%d", &n) == 1) {
		int u, v;

		fto (i, 1, n) {
			heavy[i] = 0;
			a[i].clear();
		}

		fto1 (i, 1, n) {
			scanf("%d%d%d", &u, &v, &edge[i]);
			a[u].pb(ii(v, i));
			a[v].pb(ii(u, i));
		}

		dfs(1);
		hld();
		buildST(1, n-1, 1);

		while (scanf("%s", &qtype), qtype[0] != 'D') {
			scanf("%d%d", &u, &v);
			if (qtype[0] == 'C') {
				update(1, n-1, 1, edgeId[u], v);
			} else {
				if (u == v) puts("0");
				else printf("%d\n", query(u, v));
			}
		}
	}

	return 0;
}