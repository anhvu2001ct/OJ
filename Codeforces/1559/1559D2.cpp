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
int const maxn = 2e5+5;

struct dsu {
	vector<int> p;

	void init(int n) {
		p.resize(n+1, 0);
	}

	int par(int u) {
		return !p[u] ? u : (p[u] = par(p[u]));
	}

	bool isDiff(int u, int v) {
		return par(u) != par(v);
	}

	bool unify(int u, int v) {
		u = par(u); v = par(v);
		if (u == v) return false;
		p[v] = u;
		return true;
	}
};

int n, m1, m2;
dsu g1, g2;

#define multi_test 0
void _main() {
	cin >> n >> m1 >> m2;
	g1.init(n); g2.init(n);
	int u, v;
	fto (i, 1, m1) {
		cin >> u >> v;
		g1.unify(u, v);
	}
	fto (i, 1, m2) {
		cin >> u >> v;
		g2.unify(u, v);
	}

	vector<int> v1, v2;
	vector<ii> ans;
	fto (i, 1, n) {
		if (g1.isDiff(1, i) && g2.isDiff(1, i)) {
			g1.unify(1, i);
			g2.unify(1, i);
			ans.push_back({1, i});
		}
		if (!g1.isDiff(1, i)) v1.push_back(i);
		if (!g2.isDiff(1, i)) v2.push_back(i);
	}

	while (!v1.empty() && !v2.empty()) {
		u = v1.back(); v = v2.back();
		if (!g2.isDiff(1, u)) {
			v1.pop_back();
			continue;
		}
		if (!g1.isDiff(1, v)) {
			v2.pop_back();
			continue;
		}
		ans.push_back({u, v});
		g1.unify(u, v);
		g2.unify(u, v);
		v1.pop_back();
		v2.pop_back();
	}

	bug(sz(ans));
	for (auto &e: ans) bug(e.first, e.second);
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