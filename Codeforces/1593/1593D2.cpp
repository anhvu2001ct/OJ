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
int const maxn = 2e5+3;

int n;
int a[maxn];

void addDiv(int x, map<int, int> &cnt) {
	for (int i = 1; (ll)i*i <= x; ++i) {
		if (x%i == 0) {
			++cnt[i];
			if (x/i != i) ++cnt[x/i];
		}
	}
}

#define multi_test 1
void _main() {
	map<int, int> cnt;
	cin >> n;
	fto (i, 1, n) {
		cin >> a[i];
		++cnt[a[i]];
	}
	fto (i, 1, n) {
		if (cnt[a[i]] >= n/2) {
			bug(-1);
			return;
		}
	}
	int ans = 0;
	fto (i, 1, n) {
		map<int, int> cnt2;
		fto (j, 1, n) {
			if (a[j] <= a[i]) continue;
			addDiv(a[j] - a[i], cnt2);
		}
		for (auto [k, v]: cnt2) {
			if (v+cnt[a[i]] >= n/2) ans = max(ans, k);
		}
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
		bugt;
	#endif
	return 0;
}