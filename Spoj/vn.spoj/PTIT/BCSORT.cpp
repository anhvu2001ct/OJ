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
#define maxn 100002

int n;
ll ans;
int a[maxn], f[maxn];

void update(int index) {
	for (; index <= n; index += index & -index) ++f[index];
}

int get(int index) {
	int res = 0;
	for (; index; index -= index & -index) res += f[index];
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	scanf("%d", &n);

	fto (i, 1, n) scanf("%d", &a[i]);

	int l = 1;
	a[n+1] = oo;
	fto (r, 1, n) {
		if (a[r] < a[r+1]) {
			if (l < r) ++ans;
			reverse(a + l, a + r + 1);
			l = r + 1;
		}
	}

	fdto (i, n, 1) {
		ans += get(a[i]);
		update(a[i]+1);
	}

	cout << ans << newl;

	return 0;
}
