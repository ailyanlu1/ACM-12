// BEGIN CUT HERE
/*

*/
// END CUT HERE
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
using namespace std;
 
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SZ size()
#define SQ(x) ((x)*(x))
#define SORT(p) sort(p.BGN,p.ED)
#define MEM(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef queue<int> QI;
typedef deque<int> DQI;
typedef set<int> SI;
typedef vector<PII> VII;
typedef queue<PII> QII;
typedef deque<PII> DQII;
typedef set<PII> SII;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef vector<LL> VL;
typedef queue<LL> QL;
typedef deque<LL> DQL;
typedef set<LL> SL;
typedef vector<PLL> VLL;
typedef queue<PLL> QLL;
typedef deque<PLL> DQLL;
typedef set<PLL> SLL;
#define Maxn 111111
#define Maxm 111111
class PotentialGeometricSequence
{
public:
    int n, m;
    int numberOfSubsequences (vector <int> d)
    {
        n = d.SZ;
        int ret = n + n - 1;
        int i, j, u, v, w;
        for(i = 0; i < n; i++) {
            for(j = i + 2; j < n; j++) {
                if(d[j] - d[j - 1] != d[i + 1] - d[i]) break;
                else ret++;
            }
        }
        return int(ret);
    }
};
 
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int d[]                   = {0,1,2};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int d[]                   = {1,2,4};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int d[]                   = {3,2,1,0};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int d[]                   = {1,2,4,8,16};
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int d[]                   = {1,3,5,5,5,5,64,4,23,2,3,4,5,4,3};
			int expected__            = 37;

			std::clock_t start__      = std::clock();
			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int d[]                   = {2,5,8,11,14};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PotentialGeometricSequence().numberOfSubsequences(vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

 
#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
