
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
    int t;
    while(t--)
    {
        ll n, k, e, m;
        cin >> n >> k >> e >> m;
        vector<int> score;
        for (ll i = 0; i < n; i++)
        {
            score.push_back(0);
        }

        for(ll i = 0; i < n-1; i++)
        {
            for (ll j = 0; j < e; j++)
            {
                ll s;
                cin >> s;
                score[i] += s;
            }
            cout << score[i];
        }

//        for(ll i = 0; i < n-1; i++)
//        {
//            cout << score[i];
//        }




/*      loop(i, 0, n) score.pb(0);

        loop(i, 0, n-1)
        {
            ll sum = 0;
            loop(j, 0, e)
            {
                ll sc;
                cin >> sc;
                sum += sc;
            }
            score[i] = sum;
        }

        ll sergysum = 0;
        loop(j, 0, e-1)
        {
            ll sc;
            cin >> sc;
            sergysum += sc;
        }
*/
    }
	return 0;
}
