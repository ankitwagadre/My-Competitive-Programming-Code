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
    int l[n + 1] = {0};

    for (int  i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int  sz = 1;
    l[0] = 1;
    for (int  i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < a[i] && l[j] > l[i]) {
                l[i] = l[j];
            }
        }

        l[i] = l[i] + 1;
        if (sz < l[i])
            sz = l[i];
    }

    printf("%d", sz);
    return 0;
}
