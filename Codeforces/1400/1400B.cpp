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
int const maxn = 1e6+3;

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int ca, cb; cin >> ca >> cb;
		ii a[2];
		fto (i, 0, 1) cin >> a[i].y;
		fto (i, 0, 1) cin >> a[i].x;
		sort(a, a+2);
		int ans = 0;
		fto (i, 0, min(a[0].y, ca / a[0].x)) {
			ca -= i * a[0].x;
			int v = min(a[1].y, ca / a[1].x);
			int cur = i + v;
			a[0].y -= i;
			a[1].y -= v;
			int tmp = cb;
			fto (j, 0, 1) {
				int v2 = min(a[j].y, tmp / a[j].x);
				tmp -= v2 * a[j].x;
				cur += v2;
			}
			ans = max(ans, cur);
			ca += i * a[0].x;
			a[0].y += i;
			a[1].y += v;
		}
		cout << ans << endl;
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
