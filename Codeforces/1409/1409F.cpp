#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(it, a) for (auto it = (a).begin(); it != (a).end(); ++it)
#define fat(i, a) for (auto i : (a))

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define bc __builtin_popcountll
#define y1 ansdj
#define endl '\n'
#define ff first
#define ss second
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define buga(a, s, e) cout << '{'; fto (i, s, e) cout << a[i] << " }"[i==e]; cout << endl
#define gn(a) #a << ": " << a << ", " <<

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}

template<typename T>
void bug(T const &var) { cout << var << endl; }

template<typename Type, typename... Args>
void bug(Type const &var, Args const &... args) {
	cout << var << ' ';
	bug(args...);
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 2e2+3;

int n, m;
string s, t;
int f[maxn][maxn][maxn];

void _main() {
	cin >> n >> m;
	cin >> s >> t;
	s = " " + s;
	fto (i, 0, n) fto (j, 0, m) fto (k, 0, n) f[i][j][k] = -oo;
	f[0][0][0] = 0;
	fto1 (i, 0, n) {
		fto (j, 0, m) {
			fto (k, 0, n) {
				if (f[i][j][k] != -oo) {
					bool s0 = s[i+1] == t[0];
					bool s1 = s[i+1] == t[1];
					bool s01 = t[0] == t[1];
					f[i+1][j][k + s0] = max(f[i+1][j][k + s0], f[i][j][k] + (s1 ? k : 0));

					if (j < m) {
						f[i+1][j+1][k+1] = max(f[i+1][j+1][k+1], f[i][j][k] + (s01 ? k : 0));
						f[i+1][j+1][k + s01] = max(f[i+1][j+1][k + s01], f[i][j][k] + k);
					}
				}
			}
		}
	}

	int ans = 0;
	fto (i, 0, m) fto (j, 0, n) ans = max(ans, f[n][i][j]);
	bug(ans);
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		_main();
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
