#include <bits/stdc++.h>
 
using namespace std;
 
#define fto(i, s, e) for (int i = s; i <= e; ++i)
#define fto1(i, s, e) for (int i = s; i < e; ++i)
#define fdto(i, s, e) for (int i = s; i >= e; --i)
#define fdto1(i, s, e) for (int i = s; i > e; --i)
#define fit(var, it) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for (__typeof(var.rbegin()) it = var.rbegin(); it != var.rend(); ++it)
 
#define newl '\n'
#define Vname(var) #var
#define debugt cerr << 0.001*clock() << newl
#define debug1(x, i) cout << Vname(x) << '[' << i << ']' << " = " << x[i] << newl
#define debug2(x, i, j) cout << Vname(x) << '[' << i << ']' << '[' << j << ']' << " = " << x[i][j] << newl
 
template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.first << ", " << v.second << ')';
}
 
#define ll long long
#define ii pair<int, int>
 
#define ff first
#define ss second
#define pb push_back
#define glen(v) ((int) (v).size())
 
#define eps 1e-15
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 10002
 
int n, k, t, mul, seed, maxC = 1 << 20;
ll base, ans, add;
ll a[5];
 
ll multi(ll a, ll n, ll mod) {
	ll res = 0, add = (a >= mod);
	while (n) {
		if (n%2) {
			res += a;
			if (res >= mod) res %= mod, add = 1;
		}
		n >>= 1;
		if (n == 0) break;
		a += a;
		if (a >= mod) a %= mod, add = 1;
	}
	return res;
}
 
ll power(ll a, ll n, ll mod) {
	ll res = 1, add = (a >= mod);
	while (n) {
		if (n%2) res = multi(res, a, mod);
		n >>= 1;
		if (n == 0) break;
		a = multi(a, a, mod);
	}
	return res + add*mod;
}
 
ll phi(ll n) {
	ll res = n;
	for (int i = 2; (ll)i * i <= n; ++i) {
		if (n%i) continue;
		res -= res/i;
		while (n%i == 0) n /= i;
	}
	if (n > 1) res -= res/n;
	return res;
}
 
int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
 
	cin >> n >> k >> t >> base;
	cin >> mul >> seed;
 
	ll _phi = phi(base);
	ll mu = power(k, t, _phi);
 
	a[0] = seed;
	fto (i, 1, n) {
		a[1] = (a[0]*mul + seed) % maxC;
		ans += power(a[1], mu, base);
		ans %= base;
		a[0] = a[1];
	}
 
	cout << ans << newl;
 
	return 0;
}
