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
int in[maxn], out[maxn], depth[maxn];
vector<int> adj[maxn];
vector<ii> prefix[maxn];

void dfs(int u) {
	static int t = 0;
	in[u] = ++t;
	prefix[depth[u]].emplace_back(t, prefix[depth[u]].back().second ^ (1 << (s[u] - 'a')));
	for (auto v: adj[u]) {
		depth[v] = depth[u] + 1;
		dfs(v);
	}
	out[u] = t;
}

#define multi_test 0
void _main() {
	cin >> n >> m;
	fto (i, 2, n) {
		int x; cin >> x;
		adj[x].emplace_back(i);
	}
	fto (i, 1, n) prefix[i].emplace_back(0, 0);
	cin >> s; s = " " + s;
	depth[1] = 1;
	dfs(1);
	int u, d;
	fto (i, 1, m) {
		cin >> u >> d;
		auto l = lower_bound(all(prefix[d]), ii(in[u], -1)) - 1;
		auto r = upper_bound(all(prefix[d]), ii(out[u], INT_MAX)) - 1;
		bug(bc(r->second ^ l->second) <= 1 ? "Yes" : "No");
	}
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