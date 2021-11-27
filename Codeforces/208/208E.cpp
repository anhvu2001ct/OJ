#ifdef _LOCAL
	#include "local_include.hpp"
#else
	#include <bits/stdc++.h>
	using namespace std;
#endif
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(it, a) for (auto it = (a).begin(); it != (a).end(); ++it)

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define bc __builtin_popcountll
#define endl '\n'
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define buga(a, s, e) fto(__i, s, e) cout << a[__i] << " \n"[__i == e];
#define bugar(a, s, e) cout << '{'; if (e < s) cout << '}'; else fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

template<typename T>
void bug(T const &var) { cout << var << endl; }

template<typename T, typename... Args>
void bug(T const &var, Args const &... args) {
	cout << var << ' ';
	bug(args...);
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e5+3;

int n, m;
vector<int> adj[maxn];
int in[maxn], out[maxn], ett[maxn], big[maxn], depth[maxn], ans[maxn], cnt[maxn];
int par[maxn][20];
vector<ii> query[maxn];

int dfsInit(int u) {
	static int t = -1;
	ett[in[u] = ++t] = u;
	int size = 1, maxs = 0;
	fto (i, 1, 16) par[u][i] = par[par[u][i-1]][i-1];
	for (auto v: adj[u]) {
		depth[v] = depth[u] + 1;
		int cs = dfsInit(v);
		size += cs;
		if (maxs < cs) maxs = cs, big[u] = v;
	}
	out[u] = t;
	return size;
}

int get(int u, int p) {
	fto (i, 0, 16) if (p & (1 << i)) u = par[u][i];
	return u;
}

void add(int u) {
	++cnt[depth[u]];
}

void dfs(int u, bool keep) {
	for (auto v: adj[u]) {
		if (v == big[u]) continue;
		dfs(v, 0);
	}
	if (big[u]) dfs(big[u], 1);
	for (auto v: adj[u]) {
		if (v == big[u]) continue;
		fto (i, in[v], out[v]) add(ett[i]);
	}
	add(u);
	for (auto &[d, id]: query[u]) ans[id] = cnt[d]-1;
	if (!keep) {
		fto (i, in[u], out[u]) --cnt[depth[ett[i]]];
	}
}

#define multi_test 0
void _main() {
	cin >> n;
	fto (i, 1, n) {
		int x; cin >> x;
		if (x) adj[x].emplace_back(i);
		par[i][0] = x;
	}
	fto (i, 1, n) if (!par[i][0]) {
		depth[i] = 1;
		dfsInit(i);
	}

	cin >> m;
	int u, p;
	fto (i, 1, m) {
		cin >> u >> p;
		query[get(u, p)].emplace_back(depth[u], i);
	}

	fto (i, 1, n) if (!par[i][0]) dfs(i, 0);
	buga(ans, 1, m);
}

int main() {
	#ifdef _LOCAL
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int t = 1; if (multi_test) cin >> t;
	while (t--) _main();

	#ifdef _LOCAL
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
