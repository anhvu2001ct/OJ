#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define forit(it, l, r) for(auto it = (l); it != (r); ++it)
#define fit(it, var) forit(it, (var).begin(), (var).end())
#define frit(it, var) forit(it, (var).rbegin(), (var).rend())

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

#define bc __builtin_popcountll
#define onb(x, bit) (x & (1 << bit))
#define gcd __gcd
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003

int l, r;
vector<ll> a;

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	fto (i, 1, 9) {
		fto1 (j, 0, 1 << i) {
			ll x = 0;
			fdto (k, i-1, 0) {
				x = x*10 + (onb(j, k) ? 7 : 4);
			}
			a.pb(x);
		}
	}

	a.pb(4444444444);
	
	scanf("%d%d", &l, &r);

	int p = lower_bound(a.begin(), a.end(), l) - a.begin();

	if (a[p] >= r) printf("%lld\n", a[p]*(r-l+1));
	else {
		ll ans = a[p]*(a[p] - l + 1);
		fto1 (i, p+1, sz(a)) {
			if (a[i] >= r) {
				ans += a[i]*(r - a[i-1]);
				break;
			}
			ans += a[i] * (a[i] - a[i-1]);
		}
		printf("%lld\n", ans);
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}