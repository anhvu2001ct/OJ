#include <bits/stdc++.h>
 
using namespace std;
 
#define fto(i, s, e) for (int i = s; i <= e; ++i)
#define fto1(i, s, e) for (int i = s; i < e; ++i)
#define fdto(i, s, e) for (int i = s; i >= e; --i)
#define fit(var, it) for (auto it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for (auto it = var.rbegin(); it != var.rend(); ++it)
 
#define newl '\n'
#define debug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define debug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define debug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl
 
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define glen(v) int((v).size())
 
template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}
 
double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 200003
 
int n, k;
int a[maxn];
deque<int> dq;
 
void push(int idx) {
	while (!dq.empty() && a[dq.back()] >= a[idx]) {
		dq.pop_back();
	}
	dq.pb(idx);
}
 
void pop(int idx) {
	while (!dq.empty() && dq.front() <= idx) dq.pop_front();
}
 
int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0); cin.tie(0);
 
	scanf("%*d");
 
	while (scanf("%d%d", &n, &k) == 2) {
		dq.clear();
		fto (i, 1, n) {
			scanf("%d", &a[i]);
			if (i < k) push(i);
		}
 
		fto (i, k, n) {
			push(i);
			pop(i-k);
			printf("%d ", a[dq.front()]);
		}
		puts("");
	}
 
	cerr << 0.001*clock() << newl; return 0;
}