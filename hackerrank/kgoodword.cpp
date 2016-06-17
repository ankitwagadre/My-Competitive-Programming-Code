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
        string word;
        ll k;
        cin >> word >> k;
        ll w[27];
        for (ll i = 0; i < 27; i++) {
            w[i] = 0;
        }
        for (ll i = 0; i < word.length(); i++) {
            ll idx = word[i] - 97;
            w[idx]++;
        }

        vector<ll> wn;
        for (ll i = 0; i < 26; i++) {
            if (w[i] > 0)
                wn.push_back(w[i]);
        }

        sort(wn.begin(), wn.end());
        ll mntotal = 100001;
        ll wntotal = 0;
        for (ll i = 0; i < wn.size(); i++) {
            ll total = 0;
            for (ll j = wn.size() - 1; j >= i; j--) {
                if (wn[j] - wn[i] > k)
                    total += wn[j] - wn[i] - k;
            }

            if (i!=0)
                wntotal += wn[i-1];

            total += wntotal;
            if (mntotal > total)
                mntotal = total;
        }

        cout << mntotal << endl;
    }

    return 0;
}
