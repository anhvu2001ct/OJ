#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define forit(it, l, r) for(auto it = (l); it != (r); ++it)
#define fit(it, var) forit(it, (var).begin(), (var).end())
#define frit(it, var) forit(it, (var).rbegin(), (var).rend())

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

#define bc __builtin_popcountll
#define onb(x, bit) ((x & (1 << bit)) != 0)
#define gcd __gcd
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL

int n, ans;
int a[1000003];
set<int> s[1000003];

int calc(int h, int id) {
	if (s[h].empty()) return -1;
	auto res = s[h].upper_bound(id);
	int ans = -1;
	if (res != s[h].end()) ans = *res, s[h].erase(res);
	return ans;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	scanf("%d", &n);

	fto1 (i, 0, n) {
		scanf("%d", &a[i]);
		s[a[i]].insert(i+1);
	}

	sort(a, a + n, greater<int>()); a[n] = 0;

	fto (i, 0, n) {
		if (a[i] != a[i-1]) fit (it, s[a[i-1]]) {
			int idx = *it;
			fdto (j, a[i-1]-1, 1) {
				idx = calc(j, idx);
				if (idx == -1) break;
			}
			++ans;
		}
	}

	cout << ans << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}