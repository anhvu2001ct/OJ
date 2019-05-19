#include <bits/stdc++.h>

using namespace std;

#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << '\n'
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << '\n'
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << '\n'

#define ll long long
#define mp make_pair
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.first << ", " << v.second << ')';
}

int Rand(int l, int r) {
	static mt19937 rg(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<>(l, r)(rg);
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003

int n, ans;
int a[maxn], cnt[maxn], sum[maxn];
set<int> s;

bool sol(int x) {
	if (sum[x] > 1) return 0;
	if (x == 1 || s.find(x-1) != s.end()) return 1;
	return 0;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (cnt[a[i]]) {
			--sum[cnt[a[i]]];
			if (!sum[cnt[a[i]]]) s.erase(cnt[a[i]]);
		}
		++sum[++cnt[a[i]]];
		if (sum[cnt[a[i]]] == 1) s.insert(cnt[a[i]]);
		if (sz(s) == 1 && (sum[*s.begin()] == 1 || *s.begin() == 1)) ans = i;
		if (sz(s) == 2) {
			int v1 = *s.begin(), v2 = *s.rbegin();
			if (v1 == 1 && sum[v1] == 1) ans = i;
			else if (v2-1 == v1 && sum[v2] == 1) ans = i;
		}
	}

	printf("%d\n", ans);

	cerr << 0.001*clock() << '\n'; return 0;
}