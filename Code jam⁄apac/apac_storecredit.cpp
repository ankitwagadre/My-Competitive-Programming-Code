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
    int n;
    cin >> n;
    for (int m = 1; m <= n; m++) {
        int c, i;
        cin >> c;
        int cost[c+1];
        cin >> i;
        memset(cost, -1, sizeof(cost));
        int k = -1, l = -1;
        bool found = false;
        cout << "Case #" << m << ": ";
        for (int j = 1; j <= i; j++ ) {
            int a;
            cin >> a;
            if (a  <= c && !found) {
                if (c - a >= 0 && cost[c - a] != -1) {
                cout << cost[c-a] << " " << j;
                found = true;
                } else {
                    cost[a] = j;
                }
            }
        }

        cout << endl;
    }

    return 0;
}
