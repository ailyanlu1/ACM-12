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
class Sortish
{
public:
    int n, m;
    long long ways (int sortedness, vector <int> seq)
    {
        long long ret = 0;
        int i, j, u, v, w;
        
        return long long(ret);
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			int sortedness            = 5;
			int seq[]                 = {4, 0, 0, 2, 0};
			long long expected__      = 2;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int sortedness            = 4;
			int seq[]                 = {0, 0, 0, 0};
			long long expected__      = 5;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int sortedness            = 2;
			int seq[]                 = {1, 3, 2};
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int sortedness            = 3;
			int seq[]                 = {0, 0, 2, 0, 0, 0};
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int sortedness            = 87;
			int seq[]                 = {2,0};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int sortedness            = 30;
			int seq[]                 = {0, 6, 3, 0, 0, 2, 10, 0, 0, 0};
			long long expected__      = 34;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int sortedness            = 100;
			int seq[]                 = {0, 13, 0, 0, 12, 0, 0, 0, 2, 0, 0, 10, 5, 0, 0, 0, 0, 0, 0, 7, 15, 16, 20};
			long long expected__      = 53447326;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int sortedness            = ;
			int seq[]                 = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int sortedness            = ;
			int seq[]                 = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int sortedness            = ;
			int seq[]                 = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = Sortish().ways(sortedness, vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
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
