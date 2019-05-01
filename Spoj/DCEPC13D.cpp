#include <bits/stdc++.h>
 
using namespace std;
 
#define fto(i, s, e) for(int i = s; i <= e; ++i)
#define fto1(i, s, e) for(int i = s; i < e; ++i)
#define fdto(i, s, e) for(int i = s; i >= e; --i)
#define fit(var, it) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for(__typeof(var.rbegin()) it = var.rbegin(); it != var.rend(); ++it)
 
#define newl '\n'
#define debugt cerr << 0.001*clock() << newl
#define debug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define debug(v, l, r) fto(_i, l, r) debug1(v, _i)
#define debug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define debug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl
 
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define glen(v) int((v).size())
 
template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}
 
#define eps 1e-15
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100
 
int n, k, p;
int inv[maxn];
ll fac[maxn];
 
ll lucas(int n, int k, int p) {
	fto (i, 2, p) {
		fac[i] = (fac[i-1] * i) % p;
		inv[i] = ((ll)(p - p/i) * inv[p%i]) % p;
	}
 
	int x, y;
	ll res = 1;
	while (k) {
		x = n%p; y = k%p;
		if (x < y) return 0;
		res *= (fac[x] * inv[fac[y]] * inv[fac[x-y]]) % p;
		res %= p;
		n /= p;
		k /= p;
	}
 
	return res;
}
 
ll power(ll a, int n, int p) {
	ll res = 1;
	while (n) {
		if (n%2) res = (res * a) % p;
		a = (a * a) % p;
		n >>= 1;
	}
	return res;
}
 
int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	scanf("%*d");
 
	fto (i, 0, 1) inv[i] = fac[i] = 1;
 
	vector<int> a;
	while (scanf("%d%d%d", &n, &k, &p) == 3) {
		a.clear();
		int tmp = p;
		fto (i, 2, 50) if (tmp%i == 0) {
			a.pb(i);
			tmp /= i;
		}
 
		ll ans = 0;
		fto1 (i, 0, glen(a)) {
			int M = p / a[i];
			ans += (lucas(n, k, a[i]) * M * power(M, a[i]-2, a[i])) % p;
			ans %= p;
		}
 
		cout << ans << newl;
	}
 
	return 0;
}