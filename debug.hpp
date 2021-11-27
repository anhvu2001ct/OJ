#include "validate.hpp"

namespace debug {
    mt19937_64 rg(chrono::steady_clock::now().time_since_epoch().count());

    template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
        return os << v.ff << ' ' << v.ss;
    }

    template<typename T> ostream& operator<< (ostream &os, vector<T> const &vec) {
        fto1 (i, 0, sz(vec)) {
            os << vec[i];
            if (i < sz(vec)-1) os << ' ';
        }
        return os;
    }

    /**
        Return an integer in range [first, last]
    **/
    ll rand(ll const &first=0, ll const &last=1e9) {
        return uniform_int_distribution<ll>(first, last)(rg);
    }

    /**
        Return a double in range [first, last]
    **/
    double randf(double const &first=0, double const &last=1) {
        return uniform_real_distribution<>(first, last)(rg);
    }

    /**
        Return a random value in the vector
    **/
    template<class T>
    T rand(const vector<T> &v) {
        return v[rand(0, sz(v)-1)];
    }

    /**
        Return a vector contains all primes in range [2, bound]
    **/
    vector<int> genPrimes(int bound) {
        vector<int> primes;
        vector<bool> p(bound+1, 1);
        for (int i = 2; (ll)i*i <= bound; ++i) {
            if (p[i]) for (int j = i*i; j <= bound; j += i) {
                p[j] = 0;
            }
        }
        fto (i, 2, bound) if (p[i]) primes.emplace_back(i);
        return primes;
    }

    /**
        Shuffle the vector
    **/
    template<typename Type>
    void shuffleVec(vector<Type> &vec) {
        shuffle(all(vec), rg);
    }

    /**
        Fill the vector by calling a function that return value
    **/
    template<typename T, typename randFn>
    void fillVec(vector<T> &vec, int n, randFn&& fn) {
        vec.resize(n);
        fat (&v, vec) v = fn();
    }

    /**
        Return a vector contains n random integers
    **/
    vector<ll> genVec(int n, ll const &l, ll const &r) {
        vector<ll> res(n); fat (&v, res) v = rand(l, r);
        return res;
    }

    /**
        Return a vector contains n unique integers in range [l, r]
    **/
    vector<ll> genUnique(int n, ll l, ll r) {
        if (r-l+1 < n) return vector<ll>();
        r = r-n+1;
        vector<ll> res(n);
        fto1 (i, 0, n) {
            res[i] = rand(l, r++);
            l = res[i] + 1;
        }
        shuffleVec(res);
        return res;
    }

    /**
        Return a vector contains a random permutation of length n
    **/
    vector<int> genPermu(int n) {
        vector<int> res(n); fto1 (i, 0, n) res[i] = i+1;
        shuffleVec(res);
        return res;
    }

    /**
        Return a string of length n whose values is defined by param 'pool'
        @param n int, length of the string
        @param pool string
        @param minLetter int, minium letters per word
        @param delim string, delimeter between each word
    **/
    string genStr(int n, string pool, int minLetter=1, string delim=" ") {
        string res;
        int cnt = 0;
        fto1 (i, 0, n) {
            res += pool[rand(0, sz(pool)-1)];
            if (++cnt >= minLetter && sz(res)+sz(delim) < n && randf() < .35) {
                cnt = 0;
                res += delim;
                i += sz(delim);
            }
        }
        return res;
    }

    string letters[] = {
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "0123456789"
    };

    /**
        Return a string of length n whose values is defined by param 'include' and 'pool'
        @param n int, length of the string
        @param include string, "aA0"
        @param pool string
        @param minLetter int, minium letters per word
        @param delim string, delimeter between each word
    **/
    string genStr2(int n, string include="111", string pool="", int minLetter=1, string delim=" ") {
        fto1 (i, 0, 3) if (include[i] == '1') pool += letters[i];
        return genStr(n, pool, minLetter, delim);
    }

    /**
        Generate a rooted tree that contains n nodes
        @param n int, number of nodes
        @param root int, root of the tree
        @param minDepth int, minium depth of the tree
    **/
    vector<ii> genTree(int n, int root = 1, int minDepth=1) {
        minDepth = max(min(minDepth, n), 1);
        vector<int> node, used(1, root);
        fto (i, 1, n) if (i != root) node.push_back(i);
        shuffleVec(node);
        vector<ii> res;
        static auto push = [&](int from) {
            res.push_back({from, node.back()});
            used.push_back(node.back());
            node.pop_back();
        };
        while (--minDepth) push(used.back());
        while (!node.empty()) push(rand(used));
        shuffleVec(res);
        return res;
    }

    /**
        Generate a weighted rooted tree that contains n nodes
        @param n int, number of nodes
        @param root int, root of the tree
        @param minDepth int, minium depth of the tree
        @param l int, lowerbound of weight
        @param r int, upperbound of weight
    **/
    vector<pair<ii, ll>> genWTree(int n, ll const &l, ll const &r, int root=1, int minDepth=1) {
        minDepth = max(min(minDepth, n), 1);
        vector<int> node, used(1, root);
        fto (i, 1, n) if (i != root) node.push_back(i);
        shuffleVec(node);
        vector<pair<ii, ll>> res;
        static auto push = [&](int from) {
            res.push_back({ii(from, node.back()), rand(l, r)});
            used.push_back(node.back());
            node.pop_back();
        };
        while (--minDepth) push(used.back());
        while (!node.empty()) push(rand(used));
        shuffleVec(res);
        return res;
    }

    /**
        Create folder 'problemId'. Inside this folder, create 'testId.inp'
        and 'testId.out'
    **/
    void makeTest(string problemId, int testId, bool runAns=1, int w=2) {
        auto makeId = [](int id, int width) {
            ostringstream ss; ss << setw(width) << setfill('0') << id;
            return ss.str();
        };
        system(("mkdir " + problemId).c_str());
        string tc = makeId(testId, w);
        // string path = problemId + "\\" + tc;
        string path = problemId + "\\";
        // system(("mkdir " + path).c_str());
        if (runAns) system("main.exe");
        system(("copy main.inp " + tc + ".inp").c_str());
        system(("copy main.out " + tc + ".out").c_str());
        system(("move " + tc + ".inp " + path).c_str());
        system(("move " + tc + ".out " + path).c_str());
    }
}