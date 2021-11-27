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
int const maxn = 3e2+3;

int n;
int a[maxn], cnt[maxn];
double f[maxn][maxn][maxn];

double calc(int x, int y, int z) {
	if (x < 0 || y < 0 || z < 0) return 0;
	if (f[x][y][z] != -1) return f[x][y][z];
	return f[x][y][z] = (n + calc(x-1, y, z)*x + calc(x+1, y-1, z)*y + calc(x, y+1, z-1)*z)/(x+y+z);
}

#define multi_test 0
void _main() {
	cin >> n;
	fto (i, 1, n) {
		cin >> a[i];
		++cnt[a[i]];
	}

	fto1 (i, 0, maxn) fto1 (j, 0, maxn) fto1 (k, 0, maxn) f[i][j][k] = -1;
	
	f[0][0][0] = 0;
	cout << fixed << setprecision(10);
	bug(calc(cnt[1], cnt[2], cnt[3]));
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