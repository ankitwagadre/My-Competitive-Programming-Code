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
    int l, n, d;
    cin >> l >> d >> n;
    char dic[d][20];
    for (int i = 0; i < d; i++) {
        cin >> dic[i];
    }

    for (int i = 1; i <= n; i++) {
        string tst;
        cin >> tst;
        bool tstbool[l][27];
        memset(tstbool, false, sizeof(tstbool));
        for (int j = 0, r = 0; j < tst.length(); j++, r++) {
            if (tst[j] == '(') {
                int k = j + 1;
                while (tst[k] != ')') {
                    tstbool[r][tst[k]-97] = true;
                    k++;
                }
                j = k;
            } else {
                int index = tst[j] - 97;
                tstbool[r][index] = true;
            }
        }

        ll cnt = 0;
        for (int m = 0; m < d; m++) {
            bool found = true;
            for (int p = 0; p < l; p++) {
                if (!tstbool[p][dic[m][p] - 97])
                    found = false;
            }
            if (found)
                cnt++;
        }

        cout << "Case #" << i << ": "<< cnt<< endl;
    }

    return 0;
}
