#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;
ll aa[1000001];

int main() {
    ll n, q;
    cin >> n >> q;
    ll start;
    ll ed;

    ll psta[q];
    ll peda[q];
    memset(aa, 0, sizeof(aa));
    vector< pair<ll, ll> > st;
    for (ll i = 0; i< n; i++)
    {
        cin >> start >> ed;
        st.push_back(make_pair(start, ed));
    }

    sort(st.begin(), st.end());

    ll pstart = 0;
    ll ped = 0;

    for (ll j = 0; j<q; j++)
    {
        cin >> psta[i] >> peda[i];
        if (j == 0)
        {
            pstart = psta[0];
            ped = peda[0];
        }
        else
        {
            if (pstart > psta[i]) pstart = psta[i];
            if (ped < peda[i]) ped = peda[i];
        }
    }

    /*for (ll i = n-1; i >= 0; i++)
    {


    }*/

    ll pf = 0, ps = 0;
    ll psz = 0;

    for (ll i = 0; i < n; i++)
    {
        if (st[i].first >= pstart && ped >= st[i].second)
        {
            if (!psz)
            {
                psz++;
                pf = st[i].first;
                ps = st[i].second;
                aa[ps] = psz;
            }
            else if (ps > st[i].second)
            {
                pf = st[i].first;
                ps = st[i].second;
                aa[ps] = psz;
            }
            else if (ps < st[i].first)
            {
                psz++;
                pf = st[i].first;
                ps = st[i].second;
                aa[ps] = psz;
            }
        }
    }
    return 0;
}
