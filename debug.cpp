#include <bits/stdc++.h>

using namespace std;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(var, it) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(var, it) for(auto it = (var).rbegin(); it != (var).rend(); ++it)

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

#define bc __builtin_popcountll
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb emplace_back
#define sz(v) int((v).size())

template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << v.ff << ' ' << v.ss;
}

char* sfm(const char *sf, ...) {
	static char res[100];va_list args;va_start(args, sf);vsnprintf(res, 100, sf, args);va_end(args);return res;
}

#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 1000000
#define nTest 1
#define Name "main"

double const pi = acos(-1);
mt19937 rg(chrono::steady_clock::now().time_since_epoch().count());

int rand() {
	return uniform_int_distribution<>(1, maxn)(rg);
}

int rand(int l, int r) {
	return uniform_int_distribution<>(l, r)(rg);
}

double rand(double l, double r) {
	return uniform_real_distribution<>(l, r)(rg);
}

template<typename Type>
Type rand(vector<Type> &vec) {
	return vec[rand(0, sz(vec)-1)];
}

template<typename Type>
void shuffleVec(vector<Type> &vec) {
	shuffle(vec.begin(), vec.end(), rg);
}

template<typename Type = int>
vector<Type> genVec(int n, Type l = 1, Type r = maxn) {
	vector<Type> res(n); fit (res, it) *it = rand(l, r);
	return res;
}

vector<ii> genTree(int n, int root = 1, int minDepth = 1) {
	minDepth = max(min(minDepth, n), 1);
	vector<int> node, used(1, root);
	fto (i, 1, n) if (i != root) node.pb(i);
	shuffleVec(node);
	vector<ii> res;
	auto push = [&](int from) {
		res.pb(from, node.back());
		used.pb(node.back());
		node.pop_back();
	};
	while (--minDepth) push(used.back());
	while (!node.empty()) push(rand(used));
	return res;
}

template<typename Type = int>
vector<pair<ii, int>> genWTree(int n, int root = 1, int minDepth = 1, Type l = 1, Type r = maxn) {
	minDepth = max(min(minDepth, n), 1);
	vector<int> node, used(1, root);
	fto (i, 1, n) if (i != root) node.pb(i);
	shuffleVec(node);
	vector<pair<ii, int>> res;
	auto push = [&](int from) {
		res.pb(ii(from, node.back()), rand(l, r));
		used.pb(node.back());
		node.pop_back();
	};
	while (--minDepth) push(used.back());
	while (!node.empty()) push(rand(used));
	return res;
}

template<typename Type>
void outf(ofstream &f, Type var) {
	f << var << endl;
}

template<typename Type>
void outf(ofstream &f, vector<Type> &vec, bool nl = 0) {
	fto1 (i, 0, sz(vec)) {
		f << vec[i] << (i == sz(vec)-1 ? "" : (nl ? "\n" : " "));
	}
}

void genTest() {
	ofstream inp(Name".inp");
	#define outp(x) outf(inp, x)
	auto n = rand(1000000, 1000000);
	auto vec = genVec(n);
	outp(n);
	outp(vec);
}

void runTest() {
	system(Name".exe");
	system(Name"_debug.exe");
}

string& removeSpace(string &str) {
	for (int i = sz(str)-1; i >= 0; --i) {
		if (str[i] != ' ') return str.erase(i);
	}
	return str;
}

void validTest(int iTest) {
	runTest();

	ifstream out(Name".out"), ans(Name".ans");
	static string answer, output;

	cerr << iTest << ": ";

	for (int i = 1; getline(ans, answer); ++i) {
		if (getline(out, output) && removeSpace(answer) == removeSpace(output)) continue;
		cerr << "Wrong answer on line " << i << ".\n";
		exit(0);
	}

	if (getline(out, output)) {
		cerr << "Warning, too much lines.\n";
		exit(0);
	}

	cerr << "OK.\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fto (iTest, 1, nTest) {
		genTest();
		validTest(iTest);
	}

	return 0;
}
