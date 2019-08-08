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

struct node {
	node *left, *right;
	int count;

	node(node *left, node *right, int count): left(left), right(right), count(count) {}
};

int n, m;
int a[maxn], depth[maxn];
int f[maxn][17];
vector<int> adj[maxn];
ii b[maxn];
node *root[maxn];

node *create(int left, int right, int pos, node *prev) {
	if (left <= pos && pos <= right) {
		if (left == right) {
			return new node(root[0], root[0], 1);
		}
		int mid = (left + right) >> 1;
		return new node(create(left, mid, pos, prev->left), create(mid+1, right, pos, prev->right), prev->count+1);
	}
	return prev;
}

void dfs(int u) {
	depth[u] = depth[f[u][0]] + 1;
	root[u] = create(1, n, a[u], root[f[u][0]]);
	fto (i, 1, 16) f[u][i] = f[f[u][i-1]][i-1];

	fto1 (i, 0, glen(adj[u])) {
		int v = adj[u][i];
		if (v == f[u][0]) continue;
		f[v][0] = u;
		dfs(v);
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	int deep = depth[u] - depth[v];
	fto (i, 0, 16) {
		if ((deep >> i) & 1) u = f[u][i];
	}

	if (u == v) return u;

	fdto (i, 16, 0) {
		if (f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	}

	return f[u][0];
}

int get(int left, int right, int k, node *p1, node *p2, node *s1, node *s2) {
	if (left == right) return left;
	int value = p1->left->count + p2->left->count - s1->left->count - s2->left->count;
	int mid = (left + right) >> 1;
	if (value < k) return get(mid+1, right, k - value, p1->right, p2->right, s1->right, s2->right);
	return get(left, mid, k, p1->left, p2->left, s1->left, s2->left);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	scanf("%d%d", &n, &m);

	fto (i, 1, n) {
		scanf("%d", &a[i]);
		b[i] = ii(a[i], i);
	}

	sort(b + 1, b + 1 + n);

	fto (i, 1, n) a[b[i].ss] = i;

	int u, v, k;

	fto1 (i, 1, n) {
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	root[0] = new node(0, 0, 0);
	root[0]->left = root[0]->right = root[0];

	dfs(1);

	while (m--) {
		scanf("%d%d%d", &u, &v, &k);
		int lca = LCA(u, v);
		printf("%d\n", b[get(1, n, k, root[u], root[v], root[lca], root[f[lca][0]])].ff);
	}

	return 0;
}