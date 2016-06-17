#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int counter = 0;
long long q5 = 0;
long long q2 = 0;
long long q1 = 0;
vector<long long> a;
int n = 0;
long long mn;
void maxmanager() {
        sort(a.begin(), a.end());
        long long mx = a[n-1];
        int cnt = 0;
        int kk = 0;
        for (int i = n - 1; i >= 0; i--) {
                if (mx == a[i])
                {
                    cnt++;
                }
                else
                {
                    kk = i + 1;
                    break;
                }
        }
        mn = a[0];
        int aa = 1;
        //printf("coiunt %d\n", cnt);
        if (cnt > 1) {
            if ((mx - mn) == 1)
                aa = 1;
            else if ((mx - mn) == 2)
                aa = 2;
            else
                aa = 5;

             for (int i = 0; i < n; i++) {
                if (i < kk)
                    a[i] = a[i] + aa*(cnt - 1);
                else
                    a[i] = a[i] + aa*(cnt - 2);
             }
             a[n-1] = a[n-1] + aa;

             counter = counter + cnt - 1;
             maxmanager();
             //sort(a.begin(), a.end());
        } else {
            return;
        }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        q5 = 0;
        q2 = 0;
        q1 = 0;
        //int n;
        scanf("%d", &n);
        //(n, 0);
        for (int i = 0; i < n; i++) {
            long long b;
            scanf("%lld", &b);
            a.push_back(b);
        }
        maxmanager();
/*
        sort(a.begin(), a.end());

        long long mx = a[n-1];
        int cnt = 0;
        int kk = 0;
        for (int i = n - 1; i >= 0; i--) {
                if (mx == a[i])
                {
                    cnt++;
                }
                else
                {
                    kk = i + 1;
                    break;
                }
        }
        long long mn = a[0];
        int aa = 1;
        //printf("coiunt %d\n", cnt);
        if (cnt > 1) {
            if ((mx - mn) == 1)
                aa = 1;
            else if ((mx - mn) == 2)
                aa = 2;
            else
                aa = 5;

             for (int i = 0; i < n; i++) {
                if (i < kk)
                    a[i] = a[i] + aa*(cnt - 1);
                else
                    a[i] = a[i] + aa*(cnt - 2);
             }
             a[n-1] = a[n-1] + aa;
        }
        sort(a.begin(), a.end());
*/
        mn = a[0];
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

        printf("%lld\n", q5 + q2 + q1 + counter);
    }


    return 0;
}
