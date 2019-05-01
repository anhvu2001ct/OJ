#include <bits/stdc++.h>

using namespace std;

#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << '\n'
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << '\n'
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << '\n'

#define ll long long
#define mp make_pair
#define pb push_back
#define sz(v) int((v).size())

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000007LL
#define maxn 100003

#define Name "main"

int Rand(int l, int r) {
	static mt19937 rg(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<>(l, r)(rg);
}

void genTest() {
	ofstream inpFile(Name".inp");
	int n = Rand(50, 100);
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

	ifstream outFile(Name".out"), ansFile(Name".ans");
	static string answer, output;

	cerr << iTest << ": ";

	for (int i = 1; getline(ansFile, answer); ++i) {
		if (getline(outFile, output) && removeSpace(answer) == removeSpace(output)) continue;
		cerr << "Wrong answer on line " << i << ".\n";
		exit(0);
	}

	if (getline(outFile, output)) {
		cerr << "Warning, too much lines.\n";
		exit(0);
	}

	cerr << "OK.\n";
}

int main() {
	ios_base::sync_with_stdio(0);

	for (int iTest = 1; iTest <= 1; ++iTest) {
		genTest();
		//validTest(iTest);
	}

	return 0;
}
