#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(var, it) for (auto it = (var).begin(); it != (var).end(); ++it)
#define frit(var, it) for (auto it = (var).rbegin(); it != (var).rend(); ++it)

#define newl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

#define bc __builtin_popcountll
#define onb(x, bit) (x & (1 << bit))
#define gcd __gcd
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}

template<class T> ostream& operator<< (ostream &os, vector<T> const &v) {
	os << sz(v) << '[';fto1 (i, 0, sz(v)) {os << v[i]; if (i < sz(v)-1) os << ',';}return os << ']';
}

char* sfm(const char *fmt, ...) {
	static char res[100];va_list args;va_start(args, fmt);vsnprintf(res, 100, fmt, args);va_end(args);return res;
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003

int digit[130];
int t, base, k, n;
ll f[65540][20];
vector<int> num[20];
string s;

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0); cin.tie(nullptr);

	fto (i, '0', '9') digit[i] = i - '0';
	fto (i, 'A', 'F') digit[i] = 10 + i - 'A';
	cin >> t;

	fto (tc, 1, t) {
		cin >> base >> k;
		cin >> s; n = sz(s);
		int m = (1 << n) - 1;

		memset(f, 0, sizeof f);
		fto1 (i, 0, n) {
			f[1 << i][digit[s[i]]%k] = 1;
		}

		fto (i, 1, n) num[i].clear();
		for (int i = m; i; i = (i-1) & m) {
			num[bc(i)].pb(i);
		}

		int b = 1;
		fto (i, 2, n) {
			b = (b * base) % k;
			fto1 (r, 0, k) {
				for (auto mask: num[i-1]) {
					fto1 (j, 0, n) {
						if (onb(mask, j)) continue;
						int mod = (r + digit[s[j]]*b)%k;
						f[mask | (1 << j)][mod] += f[mask][r];
					}
				}
			}
		}

		cout << sfm("Case %d: ", tc) << f[m][0] << newl;
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << newl;
	#endif
	return 0;
}