#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int hh[100000][2];

int main() {
    int n;
    scanf("%d", &n);
    int c[n+1] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    int a[n+1] = {0};
    int b[n+1] = {0};
    for (int i = 1; i <= n-1; i++) {
        scanf("%d  %d", &a[i], &b[i]);
    }

    bool clr[n+1];
    memset(clr, false, sizeof(clr));
    for (int i = 1; i <= n ; i++)
    {
        memset(clr, false, sizeof(clr));
        long long sum = 1;
        for (int k = 1; k <= n; k++)
        {
            for (int j = 1; j <= n-1; j++)
            {
                if (a[j] == k || b[j] == k)
                {
                    if (!c[b[j]])
                    {
                        sum = sum + 1;
                        c[b[j]] = true;
                    }
                    if (!c[a[j]])
                    {
                        sum = sum + 1;
                        c[a[j]] = true;
                    }
                }
            }
        }
    }

    return 0;
}
