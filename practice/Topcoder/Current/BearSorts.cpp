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
class BearSorts
{
public:
    int n, m;
    int index (vector <int> sortedSequence)
    {
        int ret = 0;
        int i, j, u, v, w;
        
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
			int sortedSequence[]      = {1,3,2};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = BearSorts().index(vector <int>(sortedSequence, sortedSequence + (sizeof sortedSequence / sizeof sortedSequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int sortedSequence[]      = {1,3,2,4};
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = BearSorts().index(vector <int>(sortedSequence, sortedSequence + (sizeof sortedSequence / sizeof sortedSequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int sortedSequence[]      = {5,4,3,2,1};
			int expected__            = 72;

			std::clock_t start__      = std::clock();
			int received__            = BearSorts().index(vector <int>(sortedSequence, sortedSequence + (sizeof sortedSequence / sizeof sortedSequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int sortedSequence[]      = {1,2,4,3,5,6,7};
			int expected__            = 33;

			std::clock_t start__      = std::clock();
			int received__            = BearSorts().index(vector <int>(sortedSequence, sortedSequence + (sizeof sortedSequence / sizeof sortedSequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int sortedSequence[]      = {40,39,38,37,36,35,20,33,32,31,30,29,2,27,26,17,24,23,22,21,19,34,18,6,3,15,14,13,12,11,10,9,8,7,25,5,4,16,28,1};
			int expected__            = 984023422;

			std::clock_t start__      = std::clock();
			int received__            = BearSorts().index(vector <int>(sortedSequence, sortedSequence + (sizeof sortedSequence / sizeof sortedSequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sortedSequence[]      = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearSorts().index(vector <int>(sortedSequence, sortedSequence + (sizeof sortedSequence / sizeof sortedSequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int sortedSequence[]      = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearSorts().index(vector <int>(sortedSequence, sortedSequence + (sizeof sortedSequence / sizeof sortedSequence[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int sortedSequence[]      = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BearSorts().index(vector <int>(sortedSequence, sortedSequence + (sizeof sortedSequence / sizeof sortedSequence[0])));
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