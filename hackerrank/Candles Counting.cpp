#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define lmt 1000000007
using namespace std;
long long  n, k;

bool contain(vector<long long> &aa, long long kk) {
    for (vector<long long>::iterator it = aa.begin(); it != aa.end(); ++it) {
        if (*it == kk)
            return true;
    }

    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    long long  h[n] = {0};
    long long c[n] = {0};
    vector< vector<long long> > a[n];
    for (long long  i = 0; i < n; i++) {
        scanf("%d %d", &h[i], &c[i]);
    }

    vector<long long> aa(1, c[0]);
    a[0].push_back(aa);
    for (long long  i = 1; i < n; i++) {
        for (long long j = i - 1; j >= 0; j--) {
            if (h[j] < h[i]) {
                for (vector< vector<long long> >::iterator it = a[j].begin(); it != a[j].end(); ++it ) {
                    vector<long long> aa = *it;
                    aa.push_back(c[i]);
                    a[i].push_back(aa);
                }
            }
        }
    }

    long long cnt = 0;
    for (long long j = 0; j < n; j++) {
        for (vector< vector<long long> >::iterator it = a[j].begin(); it != a[j].end(); ++it ) {
            bool found = true;
            for (long long i = 1; i <= k; i++) {
                if (!contain(*it, i)) {
                    found = false;
                    break;
                }
            }
            if (found)
                cnt = (cnt+1)%lmt;
        }
    }

    printf("%lld", cnt);
    return 0;
}
