#include <iostream>
#include <vector>
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
        ll a[n];
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> sm;
        ll mxsm = a[0];
        bool allnegative = true;
        ll negmx = a[0];
        for(ll i = 0; i < n; i++) {
            if (a[i] >= 0) {
                allnegative = false;
                break;
            }
            if (negmx < a[i])
                negmx = a[i];
        }

        if (allnegative) {
            mxsm = negmx;
        } else {
            ll lsm = 0;
            for(ll i = 0; i < n; i++) {
                if (a[i] < 0) {
                    sm.push_back(lsm);
                    lsm = 0;
                } else {
                    lsm += a[i];
                    if (i == n-1 && lsm > 0) {
                        sm.push_back(lsm);
                    }
                }
            }

            for(ll i = 0; i < sm.size() - 1; i++) {
            if (mxsm < sm[i] + sm[i+1])
                mxsm = sm[i] + sm[i+1];
            }
        }

        cout << mxsm << endl;
    }

    return 0;
}
