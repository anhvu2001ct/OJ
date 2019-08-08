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
#define OO 1000000000000000007LL
#define maxn 10000

ll calc[30];

ll power(ll a, ll n, ll mod) {
	ll b = 1;
	while (n) {
		if (n%2) b = (a * b) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return b;
}

ll f(int n) {
	return power(calc[26], n/27, 27) * calc[n%27];
}

ll F(int n) {
	ll res = 1;
	for (ll i = 1; i <= n; i *= 3) res = res * f(n/i) % 27;
	return res;
}

int E(int n) {
	int res = 0;
	while (n) n /= 3, res += n;
	return res;
}

ll mod27(int n, int k) {
	int e = E(n) - E(k) - E(n-k);
	return power(3, e, 27) * F(n) * power(F(k)*F(n-k)%27, 17, 27) % 27;
}

ll inv[maxn], fact[maxn];

ll lucas(int n, int k, int p) {
	fto (i, 2, p) {
		fact[i] = fact[i-1] * i % p;
		inv[i] = p - p/i * inv[p%i] % p;
	}

	ll ans = 1;

	while (k) {
		int x = n%p;
		int y = k%p;
		if (x < y) return 0;
		ans *= (fact[x] * inv[fact[y]] % p) * inv[fact[x-y]] % p;
		n /= p;
		k /= p;
	}

	return ans;
}

int numbers[] = {11, 13, 37, 27};
int phi[] = {10, 12, 36, 18};
ll arr[4];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	scanf("%*d");

	int n, k;
	calc[0] = inv[0] = inv[1] = fact[0] = fact[1] = 1;

	fto (i, 1, 26) {
		if (i%3) calc[i] = calc[i-1] * i % 27;
		else calc[i] = calc[i-1];
	}

	while (scanf("%d%d", &n, &k) != EOF) {
		fto (i, 0, 2) arr[i] = lucas(n, k, numbers[i]);
		arr[3] = mod27(n, k);

		ll ans = 0;

		fto (i, 0, 3) {
			ll M = 142857 / numbers[i];
			ans = (ans + arr[i] * M * power(M, phi[i]-1, numbers[i])) % 142857;
		}

		cout << ans << newl;
	}
	
	cout << (-6 % 3) << newl;

	return 0;
}