#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(it, a) for (auto it = (a).begin(); it != (a).end(); ++it)
#define fat(i, a) for (auto i : (a))

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define bc __builtin_popcountll
#define y1 ansdj
#define endl '\n'
#define x first
#define y second
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define buga(a, s, e) cout << '{'; fto (i, s, e) cout << a[i] << " }"[i==e]; cout << endl
#define gn(a) #a << ": " << a << ", " <<

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

template<typename T>
void bug(T const &var) { cout << var << endl; }

template<typename Type, typename... Args>
void bug(Type const &var, Args const &... args) {
	cout << var << ' ';
	bug(args...);
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e5+3;

int n, m;
vector<ll> w;
vector<int> e[maxn];

int dfs(int u, int p) {
	int cnt = 1;
	fat (v, e[u]) {
		if (v == p) continue;
		ll child = dfs(v, u);
		w.push_back(child*(n-child));
		cnt += child;
	}
	return cnt;
}

void _main() {
	cin >> n;
	fto (i, 1, n) {
		e[i].clear();
	}
	fto1 (i, 1, n) {
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	w.clear();
	dfs(1, 0);
	sort(all(w));
	cin >> m;
	vector<ll> a(m);
	fto1 (i, 0, m) cin >> a[i];
	while (sz(a) < sz(w)) a.push_back(1);
	sort(all(a));
	while (sz(a) > sz(w)) {
		ll val = a.back();
		a.pop_back();
		val = val*a.back()%oo;
		a.pop_back();
		a.push_back(val);
	}
	ll ans = 0;
	fto1 (i, 0, sz(w)) {
		ans += (w[i]%oo)*a[i]%oo;
		ans %= oo;
	}
	bug(ans);
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		_main();
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
