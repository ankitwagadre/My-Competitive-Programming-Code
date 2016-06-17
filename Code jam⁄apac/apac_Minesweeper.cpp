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
int gd[301][301];
bool vs[301][301];
int n;

bool visit(int i, int j) {
    if (i - 1 >= 0 && j - 1 >= 0 && !vs[i-1][j-1])
    {
        vs[i-1][j - 1] = true;
        if (gd[i-1][j-1]  == 0) visit(i-1, j-1);
    }

    if (i - 1 >= 0 && !vs[i-1][j])
    {
        vs[i-1][j] = true;
        if (gd[i-1][j]  == 0) visit(i-1, j);
    }

    if (i - 1 >= 0 && j + 1 <= n - 1 && !vs[i-1][j+1])
    {
        vs[i-1][j+1] = true;
        if (gd[i-1][j+1]  == 0) visit(i-1, j+1);
    }

    if (j - 1 >= 0 && !vs[i][j-1])
    {
        vs[i][j-1] = true;
        if (gd[i][j-1]  == 0) visit(i, j-1);
    }

    if (j + 1 <= n-1 && !vs[i][j+1])
    {
        vs[i][j+1] = true;
        if (gd[i][j+1]  == 0) visit(i, j+1);
    }

    if (i + 1 <= n-1 &&  j - 1 >= 0 && !vs[i+1][j-1])
    {
        vs[i+1][j-1] = true;
        if (gd[i+1][j-1]  == 0) visit(i+1, j-1);
    }

    if (i + 1 <= n-1 && !vs[i+1][j])
    {
        vs[i+1][j] = true;
        if (gd[i+1][j]  == 0) visit(i+1, j);
    }

    if (i + 1 <= n-1 && j + 1 <= n-1 && !vs[i+1][j+1])
    {
        vs[i+1][j+1] = true;
        if (gd[i+1][j+1]  == 0) visit(i+1, j+1);
    }
}

int main() {
    freopen("A-large-practice.in","rt",stdin);
	freopen("A.out","wt",stdout);
    int t;
    cin >> t;
    for (int m = 1; m <= t; m++) {
        cout << "Case #" << m << ": ";
        cin >> n;
        string g[n];
        memset(gd, 0, sizeof(gd));
        memset(vs, false, sizeof(vs));
        for(int i = 0; i < n; i++) {
            cin >> g[i];
            for(int j = 0; j < n; j++) {
                if (g[i][j] == '*')
                {
                    if (i - 1 >= 0 && j - 1 >= 0)
                        gd[i-1][j - 1]++;

                    if (i - 1 >= 0)
                        gd[i-1][j]++;

                    if (i - 1 >= 0 && j + 1 <= n-1)
                        gd[i-1][j + 1]++;

                    if (j - 1 >= 0)
                        gd[i][j - 1]++;

                    if (j + 1 <= n -1)
                        gd[i][j+1]++;

                    if (i + 1 <= n-1 && j - 1 >= 0)
                        gd[i+1][j - 1]++;

                    if (i + 1 <= n-1)
                        gd[i+1][j]++;

                    if (i + 1 <= n-1 && j + 1 <= n-1)
                        gd[i+1][j+1]++;

                    gd[i][j] = -1;
                    vs[i][j] = true;
                }
            }
        }

        ll cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (!vs[i][j] && gd[i][j] == 0)
                {
                    visit(i,j);
                    cnt++;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (!vs[i][j] && gd[i][j] > 0)
                {
                    cnt++;
                }
            }
        }


        cout << cnt << endl;
    }

    return 0;
}
