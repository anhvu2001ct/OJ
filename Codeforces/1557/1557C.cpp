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

int n, k;
ll fac[maxn];

ll power(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n%2) res = res * a % oo;
		a = a * a % oo;
		n >>= 1;
	}
	return res;
}

ll C(int k, int n) {
	if (k > n) return 0;
	return (fac[n] * power(fac[k], oo-2) % oo) * power(fac[n-k], oo-2) % oo;
}

#define multi_test 1
void _main() {
	cin >> n >> k;
	fac[0] = 1;
	fto (i, 1, n) fac[i] = fac[i-1] * i % oo;

	ll sum = 0;
	fto1 (i, 0, n) {
		sum += C(i, n);
		sum %= oo;
		++i;
	}

	ll cnt = 1, ans = 0;
	fdto (i, k-1, 0) {
		ll newCnt = sum;
		if (n%2) ++newCnt;
		else ans += power(2, (ll)i*n) * cnt % oo;
		cnt = cnt * newCnt % oo;
	}
	bug((ans + cnt) % oo);
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