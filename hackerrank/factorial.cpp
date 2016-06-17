#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 40;
    long long a[n+1] = {1, 1};

    for (int i = 1; i <= n; i++) {
        a[i] = a[i-1]*i;
        cout <<"fact of i "<< i << "is "<< a[i]<<endl;
    }

    return 0;
}
