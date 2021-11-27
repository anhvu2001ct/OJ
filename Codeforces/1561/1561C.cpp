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
int const maxn = 2e5+3;
	
int n;
vector<int> a[maxn];
ii b[maxn];
	
#define multi_test 1
void _main() {
	cin >> n;
	fto (i, 1, n) {
		int k; cin >> k;
		a[i].resize(k);
		b[i] = {0, i};
		fto1 (j, 0, k) {
			cin >> a[i][j];
			b[i].first = max(b[i].first, a[i][j] - j + 1);
		}
	}
	sort(b+1, b+1+n);
	ll ans = 0, cur = 0;
	fto (i, 1, n) {
		if (cur < b[i].first) {
			ans += b[i].first - cur;
			cur = b[i].first;
		}
		cur += sz(a[b[i].second]);
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