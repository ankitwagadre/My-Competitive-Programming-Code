

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//int col[502][502][502] = {0};
//int row[502][502][502] = {0};

int main() {
    int m,n;
    int sz = 0;
    scanf("%d %d", &m, &n);
    char str[m+1][n+1];
    for (int i = 0; i < m; i++) {
        scanf("%s", str[i]);
    }

    for (int i = 0; i < m - 1; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (str[i][j] == 'x') {
                k = j + 1;
            } else {
                if (j <= k)
                    continue;

                for (int q = k; q < j; q++) {
                    int l;
                    for (l = i + 1; l < m; l++) {
                        if (str[l][q] == 'x' || str[l][j] == 'x') {
                            break;
                        }
                    }

                    int szz = 2*((j-q) +(l - i - 1));
                    if (sz < szz)
                        sz = szz;
                }
            }
        }
    }

    if (sz == 0)
        printf("impossible");
    else
        printf("%d", sz);

    return 0;
}
