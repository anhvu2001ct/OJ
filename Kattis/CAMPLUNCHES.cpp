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
int const maxn = 1e3+3;

int n, k, x, l, r;
int a[maxn];
bool f[maxn][maxn*10];

#define multi_test 0
void _main() {
	cin >> n;
	fto (i, 1, n) cin >> a[i];
	cin >> k >> x >> l >> r;
	f[0][0] = 1;
	fto (i, 1, n) {
		f[i][0] = 1;
		fto (j, 1, r) {
			f[i][j] = f[i-1][j];
			if (a[i] <= j) f[i][j] = max(f[i][j], f[i-1][j - a[i]]);
		}
	}

	int vmax = k*x;
	fdto (i, r, l) {
		if (i%x == 0 && i <= vmax && f[n][i]) {
			bug(i);
			return;
		}
	}
	bug("impossible");
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