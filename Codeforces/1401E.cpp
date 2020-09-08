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
int const maxn = 1e6+3;

int n, m;
ii a[maxn];
int ft[maxn];

void update(int idx, int val) {
	for (; idx <= 1e6; idx += idx & -idx)
		ft[idx] += val;
}

int get(int idx) {
	int res = 0;
	for (; idx; idx -= idx & -idx)
		res += ft[idx];
	return res;
}

void _main() {
	cin >> n >> m;
	ll ans = 1;
	vector<pair<ii, int>> c;
	fto (i, 1, n) {
		int y, l, r; cin >> y >> l >> r;
		if (l == 0 && r == 1e6) ++ans;
		a[i] = {l, r};
		c.push_back({{y, 1}, i});
	}
	fto (i, 1, m) {
		int x, l, r; cin >> x >> l >> r;
		if (l == 0 && r == 1e6) ++ans;
		c.push_back({{l, 0}, x});
		c.push_back({{r, 2}, x});
	}
	sort(all(c));
	fat (&v, c) {
		if (v.x.y == 1) {
			ans += get(a[v.y].y);
			if (a[v.y].x > 1) ans -= get(a[v.y].x-1);
		} else if (v.x.y == 0) {
			update(v.y, 1);
		} else {
			update(v.y, -1);
		}
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
	// cin >> t;
	while (t--) {
		_main();
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
