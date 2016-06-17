#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

long long f[21] = {1, 1};

long long fact(int a, int b) {
    long long r = 1;
    for (int i = b+1;i<=a;i++) {
        r = r*i;
    }

    return r;
}

int main() {
    for (int i = 2; i <= 20; i++) {
        f[i] = f[i-1]*i;
    }

    long long pt = 300000;
    bool prime[pt+1];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for (long long i = 2; i*i <= pt; i++) {
        if (prime[i] == true) {
            for (long long j = i*i; j <= pt; j += i)
                prime[j] = false;
        }
    }

    long long  t;
    scanf("%lld", &t);
    while (t--) {
        long long  n, cnt;
        scanf("%lld", &n);
        long long  k = n/4;
        cnt = 0;
        for (long long  j = 0; j <= k; j++) {
            long long  i = n - j*4;
            //printf("%lld\n", j);
            cnt += fact(i+j, i)/(f[j]);
        }

        long long counter = 0;
        for (long long i = 0; i <= cnt; i ++) {
            if (prime[i] == true)
                counter++;
        }

       printf("%lld\n", counter);
    }

    return 0;
}
