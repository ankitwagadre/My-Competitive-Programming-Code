#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;
ll ss[1000001];

int main() {
    ll n, q;
    cin >> n >> q;
    ll start;
    ll ed;
    ll pstart;
    ll ped;
    //ll psta[q];
    //ps
    vector< pair<ll, ll> > st;
    for (ll i = 0; i< n; i++)
    {
        cin >> start >> ed;
        st.push_back(make_pair(start, ed));
    }

    sort(st.begin(), st.end());

    for (ll j = 0; j<q; j++)
    {
        cin >> pstart >> ped;
        ll pf = 0, ps = 0;
        ll psz = 0;

        for (ll i = 0; i< n; i++)
        {
            if (st[i].first >= pstart && ped >= st[i].second)
            {
                if (!psz)
                {
                    psz++;
                    pf = st[i].first;
                    ps = st[i].second;
                }
                else if (ps > st[i].second)
                {
                    pf = st[i].first;
                    ps = st[i].second;
                }
                else if (ps < st[i].first)
                {
                    psz++;
                    pf = st[i].first;
                    ps = st[i].second;
                }
            }
        }

        cout << psz<<endl;

    }
    return 0;
}
