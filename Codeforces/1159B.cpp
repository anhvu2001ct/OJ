#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define newl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

#define ll long long
#define mp make_pair
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.first << ", " << v.second << ')';
}

template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 300003

int n, mx = -oo, mn = oo, ans = oo;
pair<int, int> a[maxn];

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0); cin.tie(nullptr);
	
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}

	sort(a + 1, a + 1 + n);

	for (int i = n; i >= 1; --i) {
		mx = max(mx, a[i].second);
		mn = min(mn, a[i].second);
		int tmp = max(mx - a[i].second, a[i].second - mn);
		if (!tmp) continue;
		ans = min(ans, a[i].first/tmp);
	}

	cout << ans << newl;

	cerr << 0.001*clock() << newl; return 0;
}