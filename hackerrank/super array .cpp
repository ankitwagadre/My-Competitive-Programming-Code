
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
        ll k = pow(2, m) - 1;
        cout << k;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for(ll i = x; i <= y; i++)
        {

        }
    }

    return 0;
}
