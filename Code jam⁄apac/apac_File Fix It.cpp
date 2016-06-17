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
    //freopen("A-small-practice.in","rt",stdin);
	//freopen("A.out","wt",stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >>m;
        string pfs[n];
        string efs[m];
        vector<string> fs[100];
        for (int j = 0; j < n; j++) {
            cin >> pfs[j];
            int l = 1;
            int p = 0;
            int nn = pfs[j].length();
            for (int k = 1; k < nn; k++) {
                if (pfs[j][k] == '/')
                {
                    fs[p].push_back(pfs[j].substr(l, k - l));
                    p++;
                    l = k + 1;
                } else if ( k == nn-1) {
                    fs[p].push_back(pfs[j].substr(l, k - l + 1));
                }
            }
        }

        ll cnt = 0;
        for (int j = 0; j < m; j++) {
            cin >> efs[j];

            int l = 1;
            int p = 0;
            int nn = efs[j].length();
            for (int k = 2; k < nn; k++) {
                if (efs[j][k] == '/' || k == nn - 1)
                {
                    bool found = false;
                    string dir;
                    if (k == nn - 1)
                        dir = efs[j].substr(l, k - l + 1);
                    else
                        dir = efs[j].substr(l, k - l);


                    for (vector<string>::iterator it = fs[p].begin(); it != fs[p].end(); ++it) {
                        if ((*it) == dir)
                        {
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        cout << " \n   p == " << p << " " << dir << endl;
                        fs[p].push_back(dir);
                        cnt++;
                    }

                    p++;
                    l = k + 1;
                }
            }
        }

        //cout << "Case #"<< i+1<< ": "<< cnt <<endl;
	}
    return 0;
}
