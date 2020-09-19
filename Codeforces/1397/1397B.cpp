#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(it, a) for(auto it = (a).begin(); it != (a).end(); ++it)
#define fat(i, a) for(auto i : (a))

#define bc __builtin_popcountll
#define y1 ansdj
#define endl '\n'

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e5+3;

int n;
int a[maxn];

ll power(ll a, int n, ll mod) {
	ll res = 1;
	int tmp = 0;
	while (n) {
		if (n%2) {
			res = res*a;
			if (res > mod || tmp == 1) tmp = 2;
		}
		a = a*a;
		if (a > mod && tmp == 0) tmp = 1;
		n /= 2;
	}
	return tmp == 2 ? -1 : res;
}

int bs(int n) {
	int ans = -1;
	int left = 1, right = 1e9;
	while (left <= right) {
		int mid = (left + right)/2;
		int value = power(mid, n-1, a[n]);
		if (value == -1) right = mid - 1;
		else {
			ans = mid;
			left = mid + 1;
		}
	}
	return ans;
}

ll solve(int c) {
	ll ans = 0;
	fto (i, 1, n) {
		ll tmp = power(c, i-1, 3e9);
		if (tmp == -1) return OO;
		ans += abs(tmp - a[i]);
	}
	return ans;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	fto (i, 1, n) cin >> a[i];
	sort(a+1, a+1+n);

	int c = bs(n);

	cout << min(solve(c), solve(c+1)) << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
