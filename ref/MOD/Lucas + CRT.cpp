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
#define OO 1000000000000000003LL
#define maxn 100003

int n, k, p;
ll fac[100];
vector<int> a;

ll power(ll a, int n, int p) {
	ll res = 1;
	while (n) {
		if (n%2) res = res*a%p;
		n >>= 1;
		a = a*a%p;
	}
	return res;
}

ll lucas(int n, int k, int p) {
	fto1 (i, 1, p) fac[i] = fac[i-1]*i%p;
	int x, y;
	ll res = 1;
	while (k) {
		x = n%p;
		y = k%p;
		if (x < y) return 0;
		res *= fac[x] * power(fac[y], p-2, p) % p * power(fac[x-y], p-2, p) % p;
		res %= p;
		n /= p;
		k /= p;
	}
	return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fac[0] = 1;

	int t; cin >> t;
	while (t--) {
		cin >> n >> k >> p;
		a.clear();
		int tmp = p;
		fto (i, 2, 50) if (tmp%i == 0) {
			a.pb(i);
			while (tmp%i == 0) tmp /= i;
		}

		ll ans = 0;
		fto1 (i, 0, sz(a)) {
			ans += lucas(n, k, a[i]) * (p/a[i]) % p * power(p/a[i], a[i]-2, a[i]) % p;
			ans %= p;
		}
		cout << ans << endl;
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}