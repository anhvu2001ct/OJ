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
int const maxn = 2e5+3;

int n, maxx;
ll sum = 0;
int c[maxn], in[maxn], out[maxn], big[maxn], cnt[maxn];
ll ans[maxn];
vector<int> ett;
vector<int> adj[maxn];

int dfs_init(int u, int p) {
	static int t = -1;
	in[u] = ++t;
	ett.emplace_back(u);
	int size = 1, maxs = 0;
	for (int v: adj[u]) {
		if (v == p) continue;
		int child = dfs_init(v, u);
		if (child > maxs) big[u] = v, maxs = child;
		size += child;
	}
	out[u] = t;
	return size;
}

void add(int color) {
	++cnt[color];
	if (maxx < cnt[color]) maxx = cnt[color], sum = color;
	else if (maxx == cnt[color]) sum += color;
}

void dfs(int u, int p, bool keep) {
	for (int v: adj[u]) {
		if (v == p || v == big[u]) continue;
		dfs(v, u, 0);
	}
	if (big[u]) dfs(big[u], u, 1);
	for (int v: adj[u]) {
		if (v == p || v == big[u]) continue;
		fto (i, in[v], out[v]) add(c[ett[i]]);
	}
	add(c[u]);
	ans[u] = sum;
	if (!keep) {
		fto (i, in[u], out[u]) --cnt[c[ett[i]]];
		maxx = sum = 0;
	}
}

#define multi_test 0
void _main() {
	cin >> n;
	fto (i, 1, n) cin >> c[i];
	int u, v;
	fto1 (i, 1, n) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs_init(1, 0);
	dfs(1, 0, 0);
	fto (i, 1, n) cout << ans[i] << ' ';
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