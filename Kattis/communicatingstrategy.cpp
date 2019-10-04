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

int n, k;
ll S;
ll a[200];
ll f[200][200];

ll power(ll a, int n) {
    ll b = 1;
    while (n) {
        if (n%2) b = (b * a) % oo;
        a = (a * a) % oo;
        n >>= 1;
    }
    return b;
}

int main() {
    #ifdef KITTENS
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    scanf("%d", &n);

    fto (i, 1, n) f[i][0] = 1;

    fto (i, 1, n) {
        printf("1 1 %d\n", i);
        fflush(stdout);
        scanf("%d%lld", &k, &S);
        if (i == 1) {
            a[1] = f[1][1] = S;
            continue;
        }
        S -= f[i-1][k];
        if (S < 0) S += oo;
        a[i] = S * power(f[i-1][k-1], oo-2);
        a[i] %= oo;
        fto (j, 1, n) {
            f[i][j] = f[i-1][j] + a[i]*f[i-1][j-1];
            f[i][j] %= oo;
        }
    }

    printf("2");
    fto (i, 1, n) printf(" %lld", a[i]);

    #ifdef KITTENS
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}