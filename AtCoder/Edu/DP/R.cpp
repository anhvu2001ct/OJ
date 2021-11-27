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
int const maxn = 50+3;

struct matrix {
	int n;
	ll a[maxn][maxn];

	static matrix power(matrix a, ll n) {
		matrix res;
		bool first = 1;
		while (n) {
			if (n%2) {
				if (first) first = 0, res = a;
				else res = multiply(res, a);
			}
			a = multiply(a, a);
			n >>= 1;
		}
		return res;
	}

	static matrix multiply(matrix &a, matrix &b) {
		matrix res;
		fto (i, 1, a.n) {
			fto (j, 1, a.n) {
				res.a[i][j] = 0;
				fto (k, 1, a.n) {
					res.a[i][j] += a.a[i][k] * b.a[k][j];
					res.a[i][j] %= oo;
				}
			}
		}
		return res;
	}
} m;

ll k;

#define multi_test 0
void _main() {
	cin >> m.n >> k;
	int n = m.n;
	fto (i, 1, n) {
		fto (j, 1, n) {
			cin >> m.a[i][j];
		}
	}

	m = matrix::power(m, k);
	ll ans = 0;
	fto (i, 1, n) fto (j, 1, n) {
		ans += m.a[i][j];// + m.a[j][i];
		ans %= oo;
	}
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