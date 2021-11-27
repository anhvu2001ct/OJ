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
int const maxn = 3e5+3;

int n, q;
string s;
int sum[maxn];
vector<int> ans[maxn];
vector<ii> que[maxn];
unordered_map<int, int> pos;

int getsum(int l, int r) {
	if (l > r) return 0;
	return sum[r] - sum[l-1];
}

#define multi_test 1
void _main() {
	cin >> n >> q >> s;
	int sign = 1;
	pos.clear();
	fto (i, 1, n) {
		sum[i] = sum[i-1] + (s[i-1] == '+' ? 1 : -1)*sign;
		sign *= -1;
		que[i].clear();
	}
	fto (i, 1, q) {
		ans[i].clear();
		int l, r; cin >> l >> r;
		if (l == r) ans[i].emplace_back(l);
		else if (getsum(l, r) != 0) que[l].emplace_back(i, r);
	}
	fdto (i, n, 1) {
		pos[sum[i] + sum[i-1]] = i;
		for (auto [id, r]: que[i]) {
			int l = i;
			if ((r-i+1)%2 == 0) ans[id].emplace_back(l++);
			ans[id].emplace_back(pos[sum[r] + sum[l-1]]);
		}
	}
	fto (i, 1, q) {
		bug(sz(ans[i]));
		buga(ans[i], 0, sz(ans[i])-1);
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