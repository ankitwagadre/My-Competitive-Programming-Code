#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

long long q5 = 0;
long long q2 = 0;
long long q1 = 0;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        q5 = 0;
        q2 = 0;
        q1 = 0;
        int n;
        scanf("%d", &n);
        vector<long long> a;//(n, 0);
        for (int i = 0; i < n; i++) {
            long long b;
            scanf("%lld", &b);
            a.push_back(b);
        }

        sort(a.begin(), a.end());
        long long mn = a[0];
        for (int i = 1; i < n; i++) {
            long long aa = a[i] + (5*q5) + (2*q2) + q1;
            if ( aa > mn) {
                long long dif = aa - mn;
                q5 = q5 + (dif/5);
                q2 = q2 + ((dif%5)/2);
                q1 = q1 + ((dif%5)%2);
                mn = aa;
            }
        }

        printf("%lld\n", q5 + q2 + q1);
    }


    return 0;
}
