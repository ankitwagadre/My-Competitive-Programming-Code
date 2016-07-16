#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int  n;

int main() {
    scanf("%d", &n);
    int  a[n + 1] = {0};
    int l[n+1];
    l[n] = -1;

    for (int  i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        l[i] = -1;
    }

    int  sz = 0;
    l[0] = a[0];
    for (int  i = 1; i < n; i++) {
        int j = sz;
        while (j >= 0) {
            if (a[i] > l[j]) {
                if (l[j+1] > a[i] || l[j+1] == -1) {
                    l[j+1] = a[i];
                }

                if (sz < j + 1)
                    sz = j+1;
                break;
            }

            if (j == 0 && l[0] > a[i]) {
                l[0] = a[i];
                break;
            }

            j--;
        }
    }

    printf("%d", sz + 1);
    return 0;
}
