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
    freopen("B-large-practice.in","rt",stdin);
	freopen("A_large.out","wt",stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
        int n;
        string mov;
        cin >> n >> mov;
        int gd[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> gd[i][j];
            }
        }

        cout << "Case #" << i + 1 << ":\n";
        if (mov == "right")
        {
            for (int i = 0; i < n; i++) {
                int k = n-1;
                for (int j = n-2; j >= 0; j--) {
                    if (gd[i][k] == gd[i][j] && gd[i][j] != 0) {
                        gd[i][k] += gd[i][j];
                        gd[i][j] = 0;
                        k--;
                    } else if (gd[i][k] == 0 && gd[i][j] > 0) {
                        gd[i][k] = gd[i][j];
                        gd[i][j] = 0;
                    } else if (gd[i][k] > 0 && gd[i][j] > 0) {
                        if (k != j+1) {
                            gd[i][k-1] = gd[i][j];
                            gd[i][j] = 0;
                        }
                        k--;
                    }

                }
            }
        }

        if (mov == "down")
        {
            for (int i = 0; i < n; i++) {
                int k = n-1;
                for (int j = n-2; j >= 0; j--) {
                    if (gd[k][i] == gd[j][i] && gd[j][i] != 0) {
                        gd[k][i] += gd[j][i];
                        gd[j][i] = 0;
                        k--;
                    } else if (gd[k][i] == 0 && gd[j][i] > 0) {
                        gd[k][i] = gd[j][i];
                        gd[j][i] = 0;
                    } else if (gd[k][i] > 0 && gd[j][i] > 0) {
                        if (k != j+1) {
                            gd[k-1][i] = gd[j][i];
                            gd[j][i] = 0;
                        }
                        k--;
                    }

                }
            }
        }

        if (mov == "left")
        {
            for (int i = 0; i < n; i++) {
                int k = 0;
                for (int j = 1; j < n; j++) {
                    if (gd[i][k] == gd[i][j] && gd[i][j] != 0) {
                        gd[i][k] += gd[i][j];
                        gd[i][j] = 0;
                        k++;
                    } else if (gd[i][k] == 0 && gd[i][j] > 0) {
                        gd[i][k] = gd[i][j];
                        gd[i][j] = 0;
                    } else if (gd[i][k] > 0 && gd[i][j] > 0) {
                        if (k != j-1) {
                            gd[i][k+1] = gd[i][j];
                            gd[i][j] = 0;
                        }
                        k++;
                    }
                }
            }
        }


        if (mov == "up")
        {
            for (int i = 0; i < n; i++) {
                int k = 0;
                for (int j = 1; j < n; j++) {
                    if (gd[k][i] == gd[j][i] && gd[j][i] != 0) {
                        gd[k][i] += gd[j][i];
                        gd[j][i] = 0;
                        k++;
                    } else if (gd[k][i] == 0 && gd[j][i] > 0) {
                        gd[k][i] = gd[j][i];
                        gd[j][i] = 0;
                    } else if (gd[k][i] > 0 && gd[j][i] > 0) {
                        if (k != j-1) {
                            gd[k+1][i] = gd[j][i];
                            gd[j][i] = 0;
                        }
                        k++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << gd[i][j] << " ";
            }
            cout << endl;
        }

	}
    return 0;
}
