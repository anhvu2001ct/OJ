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
int const maxn = 3e5+3;

int n;
ll hashP, ans;
ll h[maxn], p[maxn];
string pat, cur;
string s[maxn];
vector<int> adj[maxn];

void dfs(int u) {
	int start = max(0, sz(cur) - sz(pat) + 1);
	cur += s[u];
	fto1 (i, sz(cur)-sz(s[u]), sz(cur)) {
		h[i] = p[i] * (cur[i] - 'a');
		if (i) h[i] += h[i-1];
		h[i] %= oo;
	}
	fto (i, start, sz(cur)-sz(pat)) {
		ll hashVal = h[i+sz(pat)-1];
		if (i) hashVal -= h[i-1];
		hashVal = ((hashVal % oo) + oo) % oo;
		if (hashVal == hashP * p[i] % oo) ++ans;
	}
	for (auto v: adj[u]) dfs(v);
	cur.resize(sz(cur) - sz(s[u]));
}

#define multi_test 0
void _main() {
	p[0] = 1;
	fto (i, 1, int(3e5)) p[i] = p[i-1] * 29 % oo;
	cur.reserve(3e5);

	cin >> n;
	fto (i, 2, n) {
		int x; cin >> x >> s[i];
		adj[x].emplace_back(i);
	}

	cin >> pat;
	hashP = pat[0] - 'a';
	fto1 (i, 1, sz(pat)) {
		hashP += p[i] * (pat[i] - 'a');
		hashP %= oo;
	}

	dfs(1);
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
