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
#define debug(x) cout << Vname(x) << " = " << x << newl
#define debug1(x, i) cout << Vname(x) << '[' << i << ']' << " = " << x[i] << newl
#define debug2(x, i, j) cout << Vname(x) << '[' << i << ']' << '[' << j << ']' << " = " << x[i][j] << newl
#define debug3(x, i, j, k) cout << Vname(x) << '[' << i << ']' << '[' << j << ']' << '[' << k << ']' << " = " << x[i][j][k] << newl
#define debuga(x, s, e) cout << Vname(x) << " = "; _debuga(x, s, e); cout << newl
    
#define ll long long
#define ii pair<int, int>
    
#define ff first
#define ss second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define cast(to, value) (static_cast<to>(value))
#define glen(v) cast(int, (v).size())
    
template<typename T> void _debuga(T const &v, int s, int e) {
    cout << '[' << s << "->" << e << ", " << (e - s + 1) << "] {"; fto (i, s, e) { cout << v[i]; if (i < e) cout << ", "; } cout << '}';
}
    
template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
    os << '(' << v.ff << ", " << v.ss << ')';
}
    
template<typename T> ostream& operator<< (ostream &os, vector<T> const &v) {
    os << '[' << glen(v) << "] {"; fto1 (i, 0, glen(v)) { os << v[i]; if (i < glen(v) - 1) os << ", "; } os << '}';
}
    
#define eps 1e-18
#define oo 1000000009
#define mod 1000000007
#define maxn 10002
    
int n, m;
int disc[maxn], low[maxn];
vector<int> a[maxn];
list<list<int> > ans;
    
void dfs(int const u) {
    static int disct = 0;
    static stack<int> s;
    disc[u] = low[u] = ++disct;
    s.push(u);
    fit (a[u], it) {
        int next = *it;
        if (!disc[next]) {
            dfs(next);
            low[u] = min(low[u], low[next]);
        } else low[u] = min(low[u], disc[next]);
    }
    if (low[u] != disc[u]) return;
    list<int> res;
    while (1) {
        int tmp = s.top();
        s.pop();
        res.pb(tmp);
        disc[tmp] = oo;
        if (tmp == u) break;
    }
    ans.pb(res);
}
    
int main() {
    #ifndef ONLINE_JUDGE
        freopen("Test.inp", "r", stdin);
        freopen("Test.out", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(0);
    
    scanf("%d%d", &n, &m);
    
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].pb(v);
    }
    
    fto (i, 1, n) {
        if (!disc[i]) {
            dfs(i);
        }
    }
    
    printf("%d\n", glen(ans));
    
    return 0;
}