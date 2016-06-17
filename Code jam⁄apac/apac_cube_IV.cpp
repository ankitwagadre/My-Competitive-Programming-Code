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
    //freopen("B-large-practice.in","rt",stdin);
	//freopen("A_large.out","wt",stdout);
	int t;
	cin >> t;
	for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        int gd[n][n];
        int dist[n*n + 1];
        int mx = 0;
        int index = 0;
        memset(dist, 0, sizeof(dist));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> gd[i][j];
            }
        }
        //cout << " hi  " << gd[1][1] <<" dd ";

        cout << "Case #" << q + 1 << ": ";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                    //cout << gd[i][j] << "  ";
                    int k = i;
                    int l = j;
                    if (i != 0)
                    {
                        k = i -1;
                        l = j;
                        if (gd[k][l] == gd[i][j] + 1)
                        {
                            dist[gd[k][l]]++;
                            //cout << gd[k][l]
                            if (mx < dist[gd[k][l]])
                            {
                                mx = dist[gd[k][l]];
                                index = gd[k][l];
                            }
                            continue;
                        }
                    }

                    if (j != 0)
                    {
                        k = i;
                        l = j - 1;
                        if (gd[k][l] == gd[i][j] + 1)
                        {
                            dist[gd[k][l]]++;
                            if (mx < dist[gd[k][l]])
                            {
                                mx = dist[gd[k][l]];
                                index = gd[k][l];
                            }
                            continue;
                        }
                    }

                    if (j != n-1)
                    {
                        k = i;
                        l = j + 1;
                        if (gd[k][l] == gd[i][j] + 1)
                        {
                            dist[gd[k][l]]++;
                            if (mx < dist[gd[k][l]])
                            {
                                mx = dist[gd[k][l]];
                                index = gd[k][l];
                            }
                            continue;
                        }
                    }

                    if (i != n-1)
                    {
                        k = i+1;
                        l = j;
                        if (gd[k][l] == gd[i][j] + 1)
                        {
                            dist[gd[k][l]]++;
                            if (mx < dist[gd[k][l]])
                            {
                                mx = dist[gd[k][l]];
                                index = gd[k][l];
                            }
                            continue;
                        }
                    }
            }
        }

        cout << index - mx << " " << mx << endl;
	}
    return 0;
}
