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
int const maxn = 16+3;

int n;
int a[maxn][maxn];
ll f[1 << maxn];

#define multi_test 0
void _main() {
	cin >> n;
	fto1 (i, 0, n) {
		fto1 (j, 0, n) {
			cin >> a[i][j];
		}
	}

	int N = 1 << n;
	fto1 (i, 1, N) {
		fto1 (j, 0, n) {
			if (!(i & (1 << j))) continue;
			fto1 (k, j+1, n) if (i & (1 << k)) f[i] += a[j][k];
		}
		for (int j = (i-1)&i; j; j = (j-1)&i) {
			f[i] = max(f[i], f[j] + f[i - j]);
		}
	}
	bug(f[N-1]);
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