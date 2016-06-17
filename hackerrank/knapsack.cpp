#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n,k;
        scanf("%d %d", &n, &k);
        int a[n];
        int s[n][k+1];
        int mx[k+1];
        for(int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                s[i][j] = 0;
            }
        }

        for (int j = 0; j <= k; j++) {
                mx[j] = 0;
        }

        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for(int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j-a[i] >= 0)
                    s[i][j] += mx[j-a[i]] + a[i];
                if (mx[j] < s[i][j])
                    mx[j] = s[i][j];
            }
        }

        cout << mx[k] << endl;
    }

    return 0;
}
