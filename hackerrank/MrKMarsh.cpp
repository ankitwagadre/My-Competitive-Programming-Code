
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int col[502][502] = {0};
int row[502][502] = {0};

int main() {
    int m,n;
    scanf("%d %d", &m, &n);
    char str[m+1][n+1];
    for (int i = 0; i < m; i++) {
        scanf("%s", str[i]);
    }

    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = m-1; j >= 0; j--) {
            if (str[j][i] != 'x') {
                col[j][i] = col[j+1][i] + 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = n-1; j >= 0; j--) {
            if (str[i][j] != 'x') {
                row[i][j] = row[i][j+1]+1;
            }
        }
    }

    int mxsz = 0;
    for (int i = 0; i < m-1; i++) {
        for (int j = n-2; j >= 0; j--) {
            int ln = row[i][j];
            for (int len = ln; len > 1; len--) {
                int mn = col[i][j]>col[i][j + len - 1]?col[i][j + len - 1]:col[i][j];
                if (mn <= 1)
                    continue;
                for (int k = mn - 1; k > 0; k--) {
                    if (row[k+i][j] >= len) {
                        int sz = 2*(len-1) + 2*(k);
                        if (mxsz < sz)
                            mxsz = sz;
                        break;
                    }
                }
            }
        }
    }

    if (mxsz == 0)
        printf("impossible");
    else
        printf("%d", mxsz);

    return 0;
}
