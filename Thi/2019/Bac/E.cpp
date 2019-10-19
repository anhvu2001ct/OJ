#include <bits/stdc++.h>
#include <ext/rope>
 
using namespace std;
 
#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(it, var) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(it, var) for(auto it = (var).rbegin(); it != (var).rend(); ++it)
 
#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl
 
#define bc __builtin_popcountll
#define onb(x, bit) (((x >> bit) & 1) != 0)
#define y1 ansdj
 
#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
 
template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}
 
template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }
 
double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000007
#define maxn 3003

int n;
int a[5];

double calc(ll x, int *a) {
	if (a[3] != 0) return 1.0*a[3]*x*x*x+a[2]*x*x+a[1]*x+a[0];
	if (a[2] != 0) return 1.0*a[2]*x*x+a[1]*x+a[0];
	return 1.0*a[1]*x+a[0];
}

ll bs_dec(ll l, ll r, int *a) {
	while (l <= r) {
		ll mid = (l+r)/2;
		if (calc(mid, a) == 0) return mid;
		if (calc(mid, a) > 0) l = mid+1;
		else r = mid-1;
	}
	return 0;
}

ll bs_inc(ll l, ll r, int *a) {
	while (l <= r) {
		ll mid = (l+r)/2;
		if (calc(mid, a) == 0) return mid;
		if (calc(mid, a) < 0) l = mid+1;
		else r = mid-1;
	}
	return 0;
}

vector<ll> solve2(int *a) {
	//bug(a[2], a[1], a[0]);
	vector<ll> res;
	//return res;
	double xm = -1.0*a[1]/(2*a[2]);
	ll x1, x2;
	if (a[2] > 0) {
		x1 = bs_dec(-OO, (ll)floor(xm), a);
		x2 = bs_inc((ll)ceil(xm), OO, a);
	} else {
		x1 = bs_inc(-OO, (ll)floor(xm), a);
		x2 = bs_dec((ll)ceil(xm), OO, a);
	}
	//bug(x1, x2, ceil(xm));
	if (calc(x1, a) == 0) res.pb(x1);
	if (calc(x2, a) == 0) res.pb(x2);
	return res;
}

vector<ll> solve3(int *a) {
	int b[5];
	b[2] = 3*a[3];
	b[1] = 2*a[2];
	b[0] = a[1];
	vector<ll> res;
	vector<ll> dx = solve2(b);
	ll x1, x2, x3;
	if (sz(dx) == 2) {
		ll xm1 = dx[0], xm2 = dx[1];
		if (a[3] > 0) {
			x1 = bs_inc(-OO, (ll)floor(xm1), a);
			x2 = bs_dec((ll)ceil(xm1), (ll)floor(xm2), a);
			x3 = bs_inc((ll)ceil(xm2), OO, a);
		} else {
			x1 = bs_dec(-OO, (ll)floor(xm1), a);
			x2 = bs_inc((ll)ceil(xm1), (ll)floor(xm2), a);
			x3 = bs_dec((ll)ceil(xm2), OO, a);
		}
		res.pb(x1);
		res.pb(x2);
		res.pb(x3);		
	}
	else {
		ll x;
		if (a[3] > 0) x = bs_inc(-OO, OO, a);
		else x = bs_dec(-OO, OO, a);
		if (calc(x, a) == 0) res.pb(x); 
	}
	return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int test;
	cin >> test;

	while (test--) {
		int n;
		cin >> n;
		fto (i, 0, 3) a[i] = 0;
		fdto (i, n, 0) cin >> a[i];
		
		
		if (n == 1) bug(-a[0]/a[1]);
		else {
			vector<ll> ans;
			if (n == 2) ans = solve2(a);
			else ans = solve3(a);
			ll mx = OO;
			fit (it, ans) mx = min(mx, *it), cout << *it << " "; 
			bug(mx);
		}
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}