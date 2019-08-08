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
#define OO 1000000000000000007LL
#define maxn 1000003

int n, k;
string s;
deque<int> dq;

void push(int index) {
	while (!dq.empty() && s[dq.back()] < s[index]) dq.pop_back();
	dq.pb(index);
}

void pop(int index) {
	while (!dq.empty() && dq.front() <= index) dq.pop_front();
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	cin >> n >> k;
	cin >> s;

	k = n - k;
	s = " " + s;

	fto (i, 1, n-k+1) {
		push(i);
	}

	printf("%c", s[dq.front()]);

	int cnt = 1;

	while (cnt < k) {
		++cnt;

		pop(dq.front());

		push(n-k+cnt);

		printf("%c", s[dq.front()]);
	}

	return 0;
}