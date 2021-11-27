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
int const maxn = 2e5+5;

int n;
ll a[maxn], d[maxn], pre[maxn], suf[maxn];

bool check(int size) {
	fto (i, 1, n) {
		pre[i] = 0;
		fto (j, i+1, min(i+size-1, n)) pre[j] = __gcd(pre[j-1], d[j]);
		if (i+size <= n) {
			suf[i+size] = 0;
			fdto (j, i+size-1, i+1) suf[j] = __gcd(suf[j+1], d[j+1]);
		}
		i += size-1;
	}
	fto (i, 1, n-size+1) {
		if (__gcd(suf[i], pre[i+size-1]) != 1) return 1;
	}
	return 0;
}

#define multi_test 1
void _main() {
	cin >> n;
	fto (i, 1, n) {
		cin >> a[i];
		if (i > 1) d[i] = max(a[i], a[i-1]) - min(a[i], a[i-1]);
	}

	int l = 2, r = n, ans = 1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid)) ans = mid, l = mid+1;
		else r = mid-1;
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