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
    for (int m = 1; m <= t; m++) {
        int n;
        cin >> n;
        cout << "Case #" << m << ": ";
        vector<long long> v1, v2;
        for (int i = 1; i <= n; i++ ) {
            int a1;
            cin >> a1;
            v1.push_back(a1);
        }

        for (int i = 1; i <= n; i++ ) {
            int a1;
            cin >> a1;
            v2.push_back(a1);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        ll sum = 0;
        for (int i = 0; i < n; i++ ) {
            sum += v1[i]*v2[n-1-i];
        }

        cout << sum;
        cout << endl;
    }

    return 0;
}
