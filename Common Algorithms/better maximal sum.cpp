
#include<bits/stdc++.h>

#define ll                    long long int
#define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
#define loopl(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
#define rloop(i,a,b)          for(int i=(int)b - 1;i>=(int)0;--i)
#define rloopl(i,a,b)         for(ll i=(ll)b - 1;i>=(ll)0;--i)
#define pb                    push_back
#define eb                    emplace_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define MAX                   1e9
#define MIN                   -1e9
#define vi                    vector<int>
#define vvi                   vector<vi>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define max(x,y)              (x>y)?x:y
#define min(x,y)              (x<y)?x:y
#define mid(s,e)              (s+(e-s)/2)
#define mini                  INT_MIN
#define itoc(c)               ((char)(((int)'0')+c))
using namespace std;

int gcd(int a, int b) { if(a==0) return b; return gcd(b%a, a);}
ll gcdl(ll a, ll b) { if(a==0) return b; return gcd(b%a, a);}

int main() {
    ll t;
    cin >> t;
    ll mod = 1000000007;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<int> a;
        int sp[n];
        ll pe[n];
        loop(i, 0, n)
        {
            ll k;
            cin >> k;
            a.pb(k);
        }
        sort(a.begin(), a.end());

        //cout << endl;
        sp[0] = a.front();
        pe[n-1] = a.back();
        loop(i, 1, n)
        {
            sp[i] = ((sp[i-1]%mod)*(a[i]%mod))%mod;
            //cout << sp[i] << " ";
        }

        //cout << endl;
        rloop(i, 0, n-1)
        {
            pe[i] = ((pe[i+1]%mod)*(a[i]%mod))%mod;
          //  cout << pe[i] << " ";
        }

        ll mx = pe[n-k];
        if (mx < sp[k-1]) mx = sp[k-1];
        for (ll i = 0; (n-k+1+i < n && i < n); i++)
        {
            ll pd = ((sp[i]%mod)*(pe[n-k+1+i]%mod))%mod;
            if (pd > mx) mx = pd;
        }

        cout << (mx%mod) << endl;
    }

	return 0;
}
