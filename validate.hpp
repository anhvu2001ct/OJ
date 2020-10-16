#include <bits/stdc++.h>

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fat(i, a) for(auto i : (a))

#define bc __builtin_popcountll
#define y1 ansdj
#define endl '\n'

#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

namespace validate {
    string& formatted(string &str) {
        for (int i = sz(str)-1; i >= 0; --i) {
            if (str[i] != ' ') return i == sz(str)-1 ? str : str.erase(i+1);
        }
        return str;
    }

    void getLines(ifstream &f, vector<string> &vec) {
        static string tmp;
        vec.clear();
        while (getline(f, tmp)) vec.push_back(formatted(tmp));
        while (vec.back() == "") vec.pop_back();
    }

    void validByLine(ifstream &out, ifstream &ans) {
        static vector<string> answer, output;
        getLines(ans, answer); getLines(out, output);
        if (sz(output) > sz(answer)) {
            cerr << "Wrong answer. Too much lines\n";
            exit(0);
        } else if (sz(output) < sz(answer)) {
            cerr << "Wrong answer on line " << sz(output)+1 << "\n";
            exit(0);
        } else {
            fto (i, 0, sz(answer)) if (answer[i] != output[i]) {
                cerr << "Wrong answer on line " << i+1 << "\n";
                exit(0);
            }
            cerr << "OK\n";
        }
    }

    void validTest(int const &iTest) {
        ifstream out("main.out"), ans("main.ans");
        cerr << iTest << ": ";
        // validByLine(out, ans);
    }
}