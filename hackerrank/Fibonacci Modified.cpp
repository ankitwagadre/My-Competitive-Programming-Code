#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long f[21];

int main() {
    int n;
    scanf("%lld %lld %d", &f[0], &f[1], &n);
    for (int i = 2; i < n; i++ ) {
        f[i] = (f[i-1]*f[i-1]) + f[i-2];
        printf("%lld\n", f[i]);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
