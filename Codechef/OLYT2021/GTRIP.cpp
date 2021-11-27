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
#define eb emplace_back
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
int const maxn = 2e3+3;

int n, m;
int f[maxn][maxn], d[maxn][maxn];
bool visited[maxn];
vector<ii> adj[maxn];

void dijkstra(int u) {
	fto (i, 1, n) {
		f[u][i] = oo;
		visited[i] = 0;
	}
	f[u][u] = 0;
	set<ii> q;
	q.insert({0, u});
	while (!q.empty()) {
		int u1 = q.begin()->second;
		q.erase(q.begin());
		if (visited[u1]) continue;
		visited[u1] = 1;
		fit (it, adj[u1]) {
			int v = it->first, w = it->second;
			int total = f[u][u1] + w;
			if (f[u][v] > total) {
				f[u][v] = total;
				q.insert({total, v});
			}
		}
	}
}

void greddy(int u) {
	fto (i, 1, n) {
		d[u][i] = oo;
		visited[i] = 0;
	}
	d[u][u] = 0;
	set<ii> q;
	q.insert({0, u});
	while (!q.empty()) {
		int u1 = q.begin()->second;
		q.erase(q.begin());
		if (visited[u1]) continue;
		visited[u1] = 1;
		int vmin = oo;
		fit (it, adj[u1]) if (!visited[it->first]) vmin = min(vmin, it->second); 
		fit (it, adj[u1]) {
			int v = it->first, w = it->second;
			if (w != vmin) continue;
			int total = d[u][u1] + w;
			if (d[u][v] > total) {
				d[u][v] = total;
				q.insert({total, v});
			}
		}
	}
}

#define multi_test 0
void _main() {
	cin >> n >> m;
	int u, v, w;
	fto (i, 1, m) {
		cin >> u >> v >> w;
		adj[u].eb(v, w);
	}

	fto (i, 1, n) {
		dijkstra(i);
		greddy(i);
	}

	int ans = 0;
	fto (i, 1, n) fto (j, 1, n) ans += f[i][j] == d[i][j];
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
		bugt;
	#endif
	return 0;
}