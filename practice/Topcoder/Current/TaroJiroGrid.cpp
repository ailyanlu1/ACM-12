// BEGIN CUT HERE
/*

*/
// END CUT HERE
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef vector <int> VI;
typedef queue <int> QI;
typedef stack <int> StaI;
typedef vector <PII> VII;
typedef queue <PII> QII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;

class TaroJiroGrid {
public:
    int n, m;
    void change(vector<string> & grid, vector<string> & G, int row, char f, char to) {
//        cout << "change " << row << endl;
        for(int j = 0; j < m; j++) {
            if(grid[row][j] == f) G[row][j] = to;
        }
    }
    bool check(vector<string> & G) {
//        cout << "check " << endl;
        int i, j, pre;
        for(j = 0; j < m; j++) {
            pre = 1;
            for(i = 1; i < n; i++) {
                if(G[i][j] == G[i - 1][j]) pre++;
                else {
                    if(pre > n / 2) return false;
                    pre = 1;
                }
            }
            if(pre > n / 2) return false;
        }
        return true;
    }
    int getNumber (vector <string> grid) {
        n = grid.SZ; m = grid[0].length();
        int i, j;
        int A = max(0, n / 2 - 4), B = min(A + 4, n - 1), C = A + 1;
//        A = 0; B = n - 1;
        int row[100];
        char from[100], to[100];
        int ret = MOD;
        int k = B - A + 1; 
//        cout << n << " " << m << " " << A << " " << B << " " << k << endl;
        for(i = 0; i < (1<<k); i++) {
            vector<string>G;
            for(j = 0; j < n; j++) G.PB(grid[j]);
            int cnt = 0;
            for(j = 0; j < 2 * k; j++) {
                if(i & (1<<j)) {
                    cnt++;
                    if(j & 1) {
                        change(grid, G, A + (j >> 1), 'W', 'B');
                    }
                    else {
                        change(grid, G, A + (j >> 1), 'B', 'W');
                    }
                }
            }
//            if(i & (1<<0)) change(G, A, 'W', 'B'), cnt++;
//            if(i & (1<<1)) change(G, A, 'B', 'W'), cnt++;
//            if(i & (1<<2)) change(G, B, 'W', 'B'), cnt++;
//            if(i & (1<<3)) change(G, B, 'B', 'W'), cnt++;
//            if(i & (1<<4)) change(G, C, 'W', 'B'), cnt++;
//            if(i & (1<<5)) change(G, C, 'B', 'W'), cnt++;
            if(check(G) && cnt < ret) ret = cnt;
        }
        return (int)(ret);
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 && !quiet )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string grid[]             = {"WB",  "BB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			string grid[]             = {"WB",  "WW"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			string grid[]             = {"WB",  "WB"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			string grid[]             = {"WBBW",  "WBWB",  "WWBB",  "BWWW"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			string grid[]             = {"WBBWBB",  "BBWBBW",  "WWBWBW",  "BWWBBB",  "WBWBBW",  "WWWBWB"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 5: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 6: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			string grid[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroJiroGrid().getNumber( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE

