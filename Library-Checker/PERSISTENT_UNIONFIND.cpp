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

struct dsu {
	vector<int> p;
	vector<tuple<int,int,int>> st;

	void init(int n) { p.resize(n+1, -1); }

	int par(int u) {
		return p[u] < 0 ? u : par(p[u]);
	}

	bool unify(int u, int v) {
		u = par(u); v = par(v);
		if (u == v) {
			st.emplace_back(0, 0, 0);
			return false;
		}
		if (p[u] > p[v]) swap(u, v);
		st.emplace_back(u, v, p[v]);
		p[u] += p[v];
		p[v] = u;
		return true;
	}

	void rollback() {
		auto [u, v, size] = st.back();
		st.pop_back();
		p[u] -= (p[v] = size);
	}
};

int n, q;
dsu group;
vector<tuple<int,int,int>> g[maxn], query[maxn];
int ans[maxn];

void dfs(int u) {
	for (auto [v, x, y]: query[u]) ans[v] = group.par(x) == group.par(y);
	for (auto [v, x, y]: g[u]) {
		group.unify(x, y);
		dfs(v);
		group.rollback();
	}
}

#define multi_test 0
void _main() {
	cin >> n >> q;
	group.init(n);
	fto (i, 1, q) {
		ans[i] = -1;
		int t, k, u, v;
		cin >> t >> k >> u >> v;
		++k; ++u; ++v;
		if (t) query[k].emplace_back(i, u, v);
		else g[k].emplace_back(i, u, v);
	}
	dfs(0);
	fto (i, 1, q) if (ans[i] != -1) bug(ans[i]);
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