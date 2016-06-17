#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    int s[n];
    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        c[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (s[i] > s[i - 1]) {
            c[i] = c[i-1] + 1;
        }
    }

    for (int i = n-2; i >= 0; i--) {
        if (s[i] > s[i + 1] && c[i] <= c[i+1])
            c[i] = c[i+1] + 1;
    }

    long long sm = 0;
    for (int i = 0; i < n; i++) {
            sm += c[i];
    }

    cout << sm;
    return 0;
}
