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
int const maxn = 5e5+3;

int n, m;
string s;
vector<int> ett;
vector<ii> query[maxn];
vector<int> adj[maxn];
int depth[maxn], big[maxn], in[maxn], out[maxn];
int cnt[maxn][30];
bool ans[maxn];

int dfs_init(int u, int p) {
	static int t = -1;
	in[u] = ++t;
	ett.emplace_back(u);
	depth[u] = depth[p] + 1;
	int size = 1, maxs = 0;
	for (auto v: adj[u]) {
		int num = dfs_init(v, u);
		if (num > maxs) big[u] = v, maxs = num;
		size += num;
	}
	out[u] = t;
	return size;
}

void add(int u) {
	++cnt[depth[u]][s[u]-'a'];
}

void dfs(int u, bool keep) {
	for (auto v: adj[u]) {
		if (v != big[u]) dfs(v, 0);
	}
	if (big[u]) dfs(big[u], 1);
	for (auto v: adj[u]) {
		if (v == big[u]) continue;
		fto (i, in[v], out[v]) add(ett[i]);
	}
	add(u);
	for (auto &[d, id]: query[u]) {
		int check = 0;
		fto (i, 'a', 'z') check += (cnt[d][i-'a']%2 == 1);
		ans[id] = check <= 1;
	}
	if (!keep) {
		fto (i, in[u], out[u]) --cnt[depth[ett[i]]][s[ett[i]]-'a'];
	}
}

#define multi_test 0
void _main() {
	cin >> n >> m;
	fto (i, 2, n) {
		int x; cin >> x;
		adj[x].emplace_back(i);
	}
	cin >> s; s = " " + s;
	int u, d;
	fto (i, 1, m) {
		cin >> u >> d;
		query[u].emplace_back(d, i);
	}
	dfs_init(1, 0);
	dfs(1, 1);
	fto (i, 1, m) bug(ans[i] ? "Yes" : "No");
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