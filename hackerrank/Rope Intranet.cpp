#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
using namespace std;
typedef long long ll;
typedef long double ld;
#define sz(x) ((int)(x).size())

int main() {
    freopen("A-large-practice.in","rt",stdin);
	freopen("A.out","wt",stdout);
	int t;
	cin >> t;
	for (int j = 0; j < t; j++) {
        int n;
        cin >> n;
        vector<pair<int, int> > rope;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            rope.push_back({a, b});
        }

        sort(rope.begin(), rope.end());
        ll cnt = 0;
        for (vector<pair<int, int> >::iterator it = rope.begin(); it != rope.end(); ++it) {
            for (vector<pair<int, int> >::iterator iti = rope.begin(); iti != it; ++iti) {
                //int s = (*it).second;
                if ((*it).second < (*iti).second && (*it).first > (*iti).first)
                    cnt++;
            }
        }
        cout << "Case #" << j + 1 << ": " << cnt <<endl;
	}

    return 0;
}
