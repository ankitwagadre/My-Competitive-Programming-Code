#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        ll a[n+1];
        a[0] = 0;
        int k = pow(2, m) - 1;
        cout << k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

    }

    return 0;
}
