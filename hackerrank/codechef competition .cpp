#include <iostream>
using namespace std;
typedef long long ll;
typedef long double ld;
#define sz(x) ((int)(x).size())

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n], b[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        ll cnt = 0;
        if (b[0] <= a[0])
            cnt++;
        for(int i = 1; i < n; i++) {
            if (b[i] <= (a[i] - a[i-1])) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
