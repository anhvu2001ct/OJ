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
int const maxn = 4e5+3;

int n, k;
int a[maxn], cnt[maxn];
vector<int> adj[maxn];

void bfs() {
	queue<int> q;
	fto (i, 1, n) if (cnt[i] <= 1) {
		q.push(i);
		a[i] = 1;
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v: adj[u]) {
			if (cnt[v] <= 1) continue;
			if (--cnt[v] == 1) {
				q.push(v);
				a[v] = a[u] + 1;
			}
		}
	}
}

#define multi_test 1
void _main() {
	cin >> n >> k;
	fto (i, 1, n) adj[i].clear();
	fto1 (i, 1, n) {
		int u, v; cin >> u >> v;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	fto (i, 1, n) cnt[i] = sz(adj[i]);
	bfs();
	sort(a+1, a+1+n);
	bug((a+1+n)-upper_bound(a+1, a+1+n, k));
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