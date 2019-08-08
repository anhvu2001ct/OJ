#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = s; i <= e; ++i)
#define fto1(i, s, e) for(int i = s; i < e; ++i)
#define fdto(i, s, e) for(int i = s; i >= e; --i)
#define fdto1(i, s, e) for(int i = s; i > e; --i)
#define fit(var, it) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for(__typeof(var.rbegin()) it = var.rbegin(); it != var.rend(); ++it)

#define newl '\n'
#define Vname(var) #var
#define debugt cerr << 0.001*clock() << newl
#define debug1(x, i) cout << Vname(x) << '[' << i << "] = " << x[i] << newl
#define debug(v, l, r) fto(_i, l, r) debug1(v, _i)
#define debug2(x, i, j) cout << Vname(x) << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define debug3(x, i, j, k) cout << Vname(x) << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.first << ", " << v.second << ')';
}

#define ll long long
#define ii pair<int, int>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define glen(v) ((int) (v).size())

#define eps 1e-15
#define oo 1000000007
#define OO 1000000000000000007LL
#define maxn 10003

int n;
ii a[maxn];
int f[maxn], g[maxn];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d", &n);

	fto (i, 1, n) {
		scanf("%d%d", &a[i].ff, &a[i].ss);
		f[0] = g[0] + a[i].ss;
		fto (j, 1, i/2) {
			f[j] = g[j-1] + a[i].ff;
			if (j*2 <= i-1) f[j] = min(f[j], g[j] + a[i].ss);
		}
		fto (j, 0, i/2) g[j] = f[j];
	}

	printf("%d\n", f[n/2]);

	return 0;
}