#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << '\n'
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << '\n'
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << '\n'

#define ll long long
#define mp make_pair
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.first << ", " << v.second << ')';
}

int rand(int l, int r) {
	static mt19937 rg(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<>(l, r)(rg);
}

template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 1003

int n;
pair<int, int> a[maxn];
map<pair<double, double>, set<double>> ct;

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			double x = a[i].second - a[j].second;
			double y = a[j].first - a[i].first;
			double c = -x*a[i].first -y*a[i].second;
			if (x) {
				y /= x;
				c /= x;
				x = 1;
			} else {
				x /= y;
				c /= y;
				y = 1;
			}
			ct[mp(x, y)].insert(c);
		}
	}

	ll cnt = 0, ans = 0;
	for (auto it = ct.begin(); it != ct.end(); ++it) {
		cnt += sz(it->second);
	}

	for (auto it = ct.begin(); it != ct.end(); ++it) {
		ll tmp = sz(it->second);
		ans += tmp * (cnt - tmp);
		cnt -= tmp;
	}

	cout << ans << '\n';

	cerr << 0.001*clock() << '\n'; return 0;
}