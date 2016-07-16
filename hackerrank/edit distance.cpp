
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
ll mod(ll a)
{
    ll r = a % md;
    return r < 0 ? r + md : r;
}


int main() {

    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a;
        cin >> b;
        int dp[a.size()+1][b.size() + 1];
        memset(dp, 0, sizeof(dp));

        loop(i, 0, a.size()+1) {
            loop(j, 0, b.size()+1) {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    int mn = min(dp[i-1][j-1], dp[i-1][j]);
                    mn = min(mn, dp[i][j-1]);
                    dp[i][j] = 1+ mn;
                }
            }
        }

        cout << dp[a.size()][b.size()] << endl;
    }

	return 0;
}
