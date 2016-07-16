
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
ll md = 1000000007;
int mod(int a)
{
    int r = a % md;
    return r < 0 ? r + md : r;
}

int main() {
    ll t;
    cin >> t;
    //ll mod = 1000000007;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<int> a;
        loop(i, 0, n)
        {
            ll k;
            cin >> k;
            a.pb(k);
        }
        sort(a.begin(), a.end());

        ll posmul = a[n-k];
        for(ll i = n-k+1; i <n; i++)
        {
            posmul = mod(mod(posmul)*mod(a[i]));
        }

        ll minmul = -md;
        /*if (a[k-1] <= 0) {
            minmul = a[0];
            for(ll i = 1; i < k; i++)
            {
                minmul = mod(mod(minmul)*mod(a[i]));
            }
        }*/

        ll pp = n;
        ll ps = -1;
        for(ll i = 1; i < n; i += 2)
        {
            if (a[i] > 0) break;
            if (abs(a[i]) > abs(a[n-k+1+i]))
            {
                pp = n-k+1+i;
                ps = i;
            }
        }

        ll negproduct = a[0];
        for(ll i = 1; i <= ps; i++)
        {
            negproduct = mod(mod(negproduct)*mod(a[i]));
        }

        for(ll i = pp; i < n; i++)
        {
            negproduct = mod(mod(negproduct)*mod(a[i]));
        }

        ll ans = max(negproduct, posmul);
        ans = max(ans, minmul);
        cout << ans << endl;
    }

	return 0;
}
