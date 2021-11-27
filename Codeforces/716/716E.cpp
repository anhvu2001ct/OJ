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
int const maxn = 2e5+3;
	
int n;
ll ans, phi, inv10;
int ett[maxn], in[maxn], out[maxn], depth[maxn], big[maxn];
ll up[maxn], down[maxn];
map<int, int> saveUp, saveReqUp;
vector<ii> adj[maxn];
	
ll power(ll a, ll n) {
	ll result = 1;
	while (n) {
		if (n%2) result = result * a % mod;
		n >>= 1;
		a = a * a % mod;
	}
	return result;
}
	
int dfsInit(int u, int p) {
	static int t = -1;
	ett[in[u] = ++t] = u;
	int size = 1, maxs = 0;
	for (auto [v, d]: adj[u]) {
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		up[v] = (power(10, depth[v]-1)*d + up[u]) % mod;
		down[v] = (down[u]*10 + d) % mod;
		int cs = dfsInit(v, u);
		if (maxs < cs) maxs = cs, big[u] = v;
		size += cs;
	}
	out[u] = t;
	return size;
}
	
void add(int u, int p) {
	// calc ?->u
	ll val = ((-down[u] * power(inv10, depth[u] - depth[p]) % mod) + mod) % mod;
	val = (val + down[p]) * power(10, depth[p]) % mod;
	val = (val + up[p]) % mod;
	ll tmp = ans;
	ans += saveUp[val];
	// calc u->?
	val = (((up[u] - up[p]) * power(inv10, 2*depth[p]) % mod) + mod) % mod;
	val -= down[p] * power(inv10, depth[p]) % mod;
	ans += saveReqUp[(val + mod) % mod];
}
	
void update(int u) {
	++saveUp[up[u]];
	++saveReqUp[(-down[u] + mod) * power(inv10, depth[u]) % mod];
}
	
void dfs(int u, int p, bool keep) {
	for (auto &[v, w]: adj[u]) {
		if (v == p || v == big[u]) continue;
		dfs(v, u, 0);
	}
	if (big[u]) dfs(big[u], u, 1);
	for (auto &[v, w]: adj[u]) {
		if (v == p || v == big[u]) continue;
		fto (i, in[v], out[v]) add(ett[i], u);
		fto (i, in[v], out[v]) update(ett[i]);
	}
	add(u, u);
	update(u);
	if (!keep) {
		saveUp.clear();
		saveReqUp.clear();
	}
}
	
int calcPhi(int n) {
	int result = n;
	for (int i = 2; (ll)i * i <= n; ++i) {
		if (n%i == 0) {
			while (n%i == 0) n /= i;
			result -= result/i;
		}
	}
	if (n > 1) result -= result/n;
	return result;
}
	
#define multi_test 0
void _main() {
	cin >> n >> mod;
	int u, v, w;
	fto1 (i, 1, n) {
		cin	>> u >> v >> w;
		++u; ++v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	phi = calcPhi(mod);
	inv10 = power(10, phi-1);
	dfsInit(1, 0);
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