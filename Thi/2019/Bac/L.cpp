#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(it, var) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(it, var) for(auto it = (var).rbegin(); it != (var).rend(); ++it)

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

#define bc __builtin_popcountll
#define onb(x, bit) (((x >> bit) & 1) != 0)
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003

int a[3000];
ll f[10];
ll s[10005]; 
int n;

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	fto (i, 1, n) cin >> a[i];
	
	sort(a+1, a+1+n);
	
	fto (i, 1, n) s[i] = (ll)a[i]*a[i];

	fto (i, 1, n-2) {
		fto1 (j, i+1, n) {
			int k = lower_bound(a+j+1, a+1+n, a[i]+a[j])-a-1;
			if (k == j) continue;
			int vuong = upper_bound(s+j+1, s+1+k, s[i]+s[j])-lower_bound(s+j+1, s+1+k, s[i]+s[j]);
			int tu = k-(upper_bound(s+j+1, s+1+k, s[i]+s[j])-s)+1;
			int nhon = k-vuong-tu-j;
			f[0] += nhon;
			f[1] += vuong;
			f[2] += tu;
			//bug(k, vuong, tu, nhon);
		}
	}

	bug(f[0], f[1], f[2]);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}