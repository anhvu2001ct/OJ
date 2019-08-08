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
#define maxn 10000

ll power(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n%2) res = (res * a) % oo;
		a = (a * a) % oo;
		n >>= 1;
	}
	return res;
}

ll f[1002];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	if (2*k > max(m, n)-1) {
		puts("0");
		return 0;
	}

	f[0] = 1;
	fto (i, 1, max(m, n)-1) f[i] = (f[i-1] * i) % oo;

	ll ans = (f[n-1] * f[m-1]) % oo;
	ans = (ans * power((f[2*k] * f[n-1-2*k]) % oo, oo-2)) % oo;
	ans = (ans * power((f[2*k] * f[m-1-2*k]) % oo, oo-2)) % oo;

	cout << ans << newl;

	return 0;
}