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
	int n = 1e6;
	outp(n);
	outp(genUnique(n, 1, 1e9));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fto (iTest, 1, 1) {
		genTest();
		runTest(0);
	}

	return 0;
}
