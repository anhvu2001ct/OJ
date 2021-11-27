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
int const maxn = 2e5+3;

bool isPrime(int n) {
	if (n == 1) return 0;
	for (int i = 2; (ll)i * i <= n; ++i) {
		if (n%i == 0) return 0;
	}
	return 1;
}

#define multi_test 1
void _main() {
	int n; cin >> n;
	string s; cin >> s;
	fto1 (i, 0, n) {
		if (!isPrime(s[i] - '0')) {
			cout << 1 << endl << s[i] << endl;
			return;
		}
	}

	fto1 (i, 0, n) {
		fto1 (j, i+1, n) {
			int val = (s[i] - '0')*10 + (s[j] - '0');
			if (!isPrime(val)) {
				cout << 2 << endl;
				cout << s[i] << s[j] << endl;
				return;
			}
		}
	}
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