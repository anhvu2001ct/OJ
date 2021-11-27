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

int n;
vector<int> adj[maxn];
int a[maxn], in[maxn], out[maxn], big[maxn];
map<int, int> cnt;
vector<int> ett;
ll ans;

int dfs_init(int u, int p) {
	static int t = -1;
	in[u] = ++t;
	ett.emplace_back(u);
	int size = 1, maxs = 0;
	for (auto v: adj[u]) {
		if (v == p) continue;
		int cs = dfs_init(v, u);
		size += cs;
		if (cs > maxs) maxs = cs, big[u] = v;
	}
	out[u] = t;
	return size;
}

void add(int u, int tot) {
	if (tot%a[u] == 0) ans += cnt[tot/a[u]];
}

void dfs(int u, int p, bool keep) {
	for (auto v: adj[u]) {
		if (v == p || v == big[u]) continue;
		dfs(v, u, 0);
	}
	if (big[u]) dfs(big[u], u, 1);
	for (auto v: adj[u]) {
		if (v == p || v == big[u]) continue;
		fto (i, in[v], out[v]) add(ett[i], a[u]);
		fto (i, in[v], out[v]) ++cnt[a[ett[i]]];
	}
	add(u, a[u]);
	++cnt[a[u]];
	if (!keep) {
		fto (i, in[u], out[u]) --cnt[a[ett[i]]];
	}
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
	fto (i, 1, n) cin >> a[i];
	dfs_init(1, 0);
	dfs(1, 0, 1);
	bug(ans);
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