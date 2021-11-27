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

int n, m1, m2;
int p1[maxn], p2[maxn];

int par(int *p, int u) {
	return !p[u] ? u : (p[u] = par(p, p[u]));
}

bool isDiff(int *p, int u, int v) {
	u = par(p, u), v = par(p, v);
	return u != v;
}

bool unify(int *p, int u, int v) {
	u = par(p, u), v = par(p, v);
	if (u == v) return 0;
	p[v] = u;
	return 1;
}

#define multi_test 0
void _main() {
	cin >> n >> m1 >> m2;
	int u, v;
	fto (i, 1, m1) {
		cin >> u >> v;
		unify(p1, u, v);
	}
	fto (i, 1, m2) {
		cin >> u >> v;
		unify(p2, u, v);
	}

	vector<ii> ans;
	fto (i, 1, n) {
		fto (j, i+1, n) {
			if (isDiff(p1, i, j) && isDiff(p2, i, j)) {
				unify(p1, i, j);
				unify(p2, i, j);
				ans.push_back({i, j});
			}
		}
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