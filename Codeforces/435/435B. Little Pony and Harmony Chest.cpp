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
#define maxn 102

int n, ans = oo, res;
int a[maxn], minP[maxn], id[maxn], value[maxn];
int f[maxn][1<<17], g[maxn][1<<17];

void process(int n) {
	int cnt = -1;
	fto (i, 2, n) minP[i] = i;
	for (int i = 2; i * i <= n; ++i) if (minP[i] == i) for (int j = i * i; j <= n; j += i) minP[j] = min(minP[j], i);
	fto (i, 2, n) if (minP[i] == i) id[i] = ++cnt;
	fto (i, 2, n) for (int j = i; j > 1; j /= minP[j]) value[i] |= (1 << id[minP[j]]);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0);

	scanf("%d", &n);

	fto (i, 1, n) scanf("%d", &a[i]);

	process(59);

	fto (i, 1, n) fto1 (j, 0, (1 << 17)) f[i][j] = oo;

	fto (i, 1, n) {
		fto (j, 1, 59) {
			int x = ((1 << 17) - 1) & (~value[j]);
			for (int k = x; ; k = x & (k-1)) {
				if (f[i][k|value[j]] > f[i-1][k] + abs(a[i] - j)) {
					f[i][k|value[j]] = f[i-1][k] + abs(a[i] - j);
					g[i][k|value[j]] = j;
					if (i == n && ans > f[i][k|value[j]]) {
						res = (k|value[j]);
						ans = f[i][res];
					}
				}
				if (!k) break;
			}
		}
	}

	vector<int> final(n+1);

	fdto (i, n, 1) {
		final[i] = g[i][res];
		res -= value[final[i]];
	}

	fto (i, 1, n) printf("%d ", final[i]);

	return 0;
}
