#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    bool prime[101];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i*i <= 100; i++) {
        if (prime[i] == true) {
            for (int j = i*i; j <= 100; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= 100; i++) {
        if (prime[i] == true) {
                cout << i << endl;
        }
    }
    return 0;
}
