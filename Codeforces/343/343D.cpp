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
#define bugan(a, s, e) fto(__i, s, e) cout << a[__i] << endl;

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
int mod = oo;
int const maxn = 5e5+3;

int n, m;
int ett[maxn], in[maxn], out[maxn], big[maxn], ans[maxn];
vector<int> que[maxn], adj[maxn];
vector<ii> op[maxn];

int dfsInit(int u, int p) {
	static int t = -1;
	ett[in[u] = ++t] = u;
	int size = 1, maxs = 0;
	for (auto v: adj[u]) {
		if (v == p) continue;
		int cs = dfsInit(v, u);
		if (maxs < cs) maxs = cs, big[u] = v;
		size += cs;
	}
	out[u] = t;
	return size;
}

set<ii> cur;
void add(int u) {
	for (auto &q: op[u]) {
		if (!q.second) cur.insert(q);
	}
}

void dfs(int u, int p, bool keep) {
	for (auto &q: op[u]) if (q.second) cur.insert(q);
	for (auto v: adj[u]) {
		if (v == p || v == big[u]) continue;
		dfs(v, u, 0);
	}
	if (big[u]) dfs(big[u], u, 1);
	for (auto v: adj[u]) {
		if (v == p || v == big[u]) continue;
		fto (i, in[v], out[v]) add(ett[i]);
	}
	add(u);
	for (auto id: que[u]) {
		auto it = cur.lower_bound(ii(id, -1));
		if (it == cur.begin()) ans[id] = 0;
		else ans[id] = (--it)->second;
	}
	if (!keep) fto (i, in[u], out[u]) for (auto &q: op[ett[i]]) cur.erase(q);
	else for (auto &q: op[u]) if (q.second) cur.erase(q);
}

#define multi_test 0
void _main() {
	cin >> n;
	int u, v;	
	fto1 (i, 1, n) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	cin >> m;
	fto (i, 1, m) {
		cin >> u >> v;
		if (u == 3) que[v].emplace_back(i);
		else op[v].emplace_back(i, u%2), op[v].back();
		ans[i] = -1;
	}
	dfsInit(1, 0);
	dfs(1, 0, 1);
	fto (i, 1, m) if (ans[i] != -1) bug(ans[i]);
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