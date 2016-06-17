#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        for(ll i = 0; i < n; i++) {
            cin>>a[i];
        }

        bool possible = false;
        ll i = 0;
        for (i = 0; i < n - 2;i++)
        {
            if (a[i] == a[i+1] && a[i] == a[i+2])
            {
                possible = true;
                break;
            }
        }

        if (possible)
            cout << "Yes"<<endl;
        else
            cout << "No" <<endl;
    }

    return 0;
}
