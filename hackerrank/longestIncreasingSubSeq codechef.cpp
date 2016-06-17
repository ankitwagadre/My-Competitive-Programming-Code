
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
        ll n;
        cin >> n;
        if (n <= 100) {
            cout << n << endl;
            for (int i = n; i > 0; i--)
            {
                cout << i;
                if (i != 1)
                    cout << " ";
            }
            cout << endl;
        }
        else
        {
            int i = 1;
            ll l = n - (n%2);
            for (i = 1; i < 100; i++)
            {
                if ((l%i == 0) && ((i + (l/i)) <= 100))
                    break;
            }
            if (n%2)
            {
                cout << l/i + i + 2 << endl;
                cout << l/i + n%2 + i<< " ";
                cout << l/i + n%2 + i + 1<< " ";
            }
            else
            {
                cout << l/i + i << endl;
            }
            for (int j = i; j > 0; j--)
            {
                cout << j << " ";
            }

            for (int j = l/i + i; j > i; j--)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

