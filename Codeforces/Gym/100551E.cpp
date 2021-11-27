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

struct DSU {
	vector<int> p;
	vector<tuple<int,int,int>> st;
	int comps;

	void init(int n) {
		p.resize(n+1, -1);
		comps = n;
	}

	int get(int u) {
		return p[u] < 0 ? u : get(p[u]);
	}

	bool unify(int u, int v) {
		u = get(u); v = get(v);
		if (u == v) return false;
		if (p[u] > p[v]) swap(u, v);
		st.emplace_back(u, v, p[v]);
		p[u] += p[v];
		p[v] = u;
		--comps;
		return true;
	}

	void rollback() {
		auto [u, v, size] = st.back();
		st.pop_back();
		p[u] -= (p[v] = size);
		++comps;
	}
} dsu;

int n, m, q;
vector<ii> edge;
vector<int> stop[maxn];
bool ans[maxn];
vector<ii> edges[4*maxn];

void add(int id, int l, int r, int ql, int qr, ii const &que) {
	if (l > qr || r < ql) return;
	if (ql <= l && qr >= r) {
		edges[id].emplace_back(que);
		return;
	}
	int mid = (l+r)/2;
	add(2*id, l, mid, ql, qr, que);
	add(2*id+1, mid+1, r, ql, qr, que);
}

void dfs(int id, int l, int r) {
	int cnt = 0;
	for (auto [u, v]: edges[id]) cnt += dsu.unify(u, v);
	if (l == r) ans[l] = dsu.comps == 1;
	else {
		int mid = (l+r)/2;
		dfs(2*id, l, mid);
		dfs(2*id+1, mid+1, r);
	}
	while (cnt--) dsu.rollback();
}

#define multi_test 0
void _main() {
	cin >> n >> m;
	dsu.init(n);
	int u, v;
	fto (i, 1, m) {
		cin >> u >> v;
		edge.emplace_back(u, v);
	}
	cin >> q;
	fto (i, 1, q) {
		int k, x; cin >> k;
		while (k--) {
			cin >> x; --x;
			stop[x].emplace_back(i);
		}
	}

	fto1 (i, 0, m) {
		stop[i].emplace_back(q+1);
		int cur = 1;
		for (auto j: stop[i]) {
			if (cur != j) add(1, 1, q, cur, j-1, edge[i]);
			cur = j+1;
		}
	}

	dfs(1, 1, q);
	fto (i, 1, q) bug(ans[i] ? "Connected" : "Disconnected");
}

int main() {
	#ifdef _LOCAL
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	freopen("disconnected.in", "r", stdin);
	freopen("disconnected.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int t = 1; if (multi_test) cin >> t;
	while (t--) _main();

	#ifdef _LOCAL
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}