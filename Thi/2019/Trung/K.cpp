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

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 1000003

int n;
int f[1000005];
int phi[1000005];

void sieve(int n) {
	fto (i, 1, n) phi[i] = i;
    for (int i = 2; (ll)i*i <= n; ++i) {
        if (phi[i] == i) for (int j = i; j <= n; j += i) phi[j] -= phi[j]/i;
    }
}

void solve(int n) {
    if (f[n] != -1) return;

    solve(n-1);
    int res1 = f[n-1];

    int cnt = 0, cur = n;
    while (cur) {
        ++cnt;
        cur /= 10;
    }

    solve(n-cnt);
    int res2 = f[n-cnt];

    solve(n-phi[n]);
    int res3 = f[n-phi[n]];
    if (res1%2 == 0) {
        f[n] = res1+1;
        return;
    }
    if (res2%2 == 0) {
        f[n] = res2+1;
        return;
    }
    if (res3%2 == 0) {
        f[n] = res3+1;
        return;
    }
    f[n] = min(res1, res2);
    f[n] = min(res3, f[n])+1;
    return;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	sieve(1e6);
    
    int test;
	cin >> test;

	fto (i, 0, 1e6) f[i] = -1;
	f[1] = 1;
	f[0] = 0;

	while (test--) {
        cin >> n;
        solve(n);
        //fto (i, 1, n) cout << f[i] << " ";
        if (f[n]%2) cout << "BACH" << endl;
        else cout << "KHOA" << endl;
	}



	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}