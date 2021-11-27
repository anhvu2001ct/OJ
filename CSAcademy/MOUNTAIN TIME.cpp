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
int const maxn = 1e3+3;

int n, m;
pair<int, list<ii>>* a[maxn*maxn];
int p[maxn*maxn];
int ans[maxn][maxn];
vector<tuple<int,int,int>> vec;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int par(int u) {
	return p[u] < 0 ? u : (p[u] = par(p[u]));
}

void merge(int u, int v, int val) {
	if (a[u]->first == a[v]->first) {
		a[u]->second.splice(a[u]->second.end(), a[v]->second);
	} else {
		if (a[u]->first < a[v]->first) swap(a[u], a[v]);
		for (auto [i, j]: a[v]->second) ans[i][j] = val;
	}
}

bool unify(int u, int v, int val) {
	u = par(u); v = par(v);
	if (u == v) return false;
	if (p[u] > p[v]) swap(u, v);
	merge(u, v, val);
	p[u] += p[v];
	p[v] = u;
	return true;
}

#define multi_test 0
void _main() {
	cin >> n >> m;
	fto1 (i, 0, n) {
		fto1 (j, 0, m) {
			int x; cin >> x;
			vec.emplace_back(x, i, j);
			p[i*m+j] = -1;
		}
	}
	sort(all(vec), greater<tuple<int,int,int>>());

	for (auto &[val, u, v]: vec) {
		a[u*m+v] = new pair<int, list<ii>>(val, {{u, v}});
		fto1 (d, 0, 4) {
			int i = u + dy[d], j = v + dx[d];
			if (i < 0 || i >= n || j < 0 || j >= m) continue;
			if (a[i*m+j] == nullptr) continue;
			unify(u*m+v, i*m+j, val);
		}
	}

	for (auto &[val, u, v]: vec) ans[u][v] = val - ans[u][v];

	fto1 (i, 0, n) {
		fto1 (j, 0, m) {
			cout << ans[i][j] << ' ';
		}
		bug("");
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