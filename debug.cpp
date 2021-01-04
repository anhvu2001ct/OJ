#include "debug.hpp"

using namespace debug;
using namespace validate;

#define oo 1000000007
#define OO 1000000000000000003LL

int const maxn = 1e7+3;
double const pi = acos(-1);

template<typename Type>
void outf(ostream &os, Type const &var) {
	os << var << endl;
}

template<typename Type, typename... Args>
void outf(ostream &os, Type const &var, Args const &... args) {
	os << var << ' ';
	outf(os, args...);
}

void runTest(bool runAns = 1) {
	system("main.exe");
	if (runAns) system("main_debug.exe");
}

void genTest() {
	#define outp(args...) outf(inp, args)
	ofstream inp("main.inp");
	auto a = genVec(6, -1, 1);
	string s; s.resize(sz(a));
	fto1 (i, 0, sz(a)) {
		if (a[i] == -1) s[i] = '?';
		else s[i] = '0' + a[i];
	}
	outp(s);
	outp(rand(1, 100), rand(1, 100));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fto (iTest, 1, 100) {
		genTest();
		runTest();
		validTest(iTest);
	}

	return 0;
}
