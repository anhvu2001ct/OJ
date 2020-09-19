#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for (int i = s; i <= e; ++i)
#define fto1(i, s, e) for (int i = s; i < e; ++i)
#define fdto(i, s, e) for (int i = s; i >= e; --i)

#define newl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 5210

int n;
bool a[maxn][maxn];
int sum[maxn][maxn];
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	fto (i, 1, n) {
		cin >> s;
		fto1 (j, 0, n/4) {
			string tmp = string("") + s[j];
			int mask = stoi(tmp, 0, 16);
			fdto (k, 3, 0) a[i][j*4 + 4-k] = (mask & (1 << k));
		}
	}

	fto (i, 1, n) {
    fto (j, 1, n) {
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]  + a[i][j];
    }
  }

  fdto (x, n, 1) if (n%x == 0) {
    bool ok = 1;
    int total = x*x;
    for (int i = x; i <= n && ok; i += x) {
      if (!ok) break;
      for (int j = x; j <= n && ok; j += x) {
        if (!ok) break;
        int val = sum[i][j] - sum[i-x][j] - sum[i][j-x] + sum[i-x][j-x];
        if (val != 0 && val != total) ok = 0;
      }
    }
    if (ok) {
      cout << x << newl;
      return 0;
    }
  }

	cerr << 0.001*clock() << newl; return 0;
}