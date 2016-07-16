
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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int gcd(int a, int b) { if(a==0) return b; return gcd(b%a, a);}
ll gcdl(ll a, ll b) { if(a==0) return b; return gcd(b%a, a);}
int dp[101][1000010];

int main() {
	int t;
	cin >> t;
	while(t--) {
        int n;
        cin >> n;
        int a[n+1];
        int totalsum = 0;
        loop(i, 0, n) {
            cin >> a[i];
            totalsum += a[i];
        }

        if (totalsum%2 != 0) cout << "NO" << endl;
        else {
            //cout << totalsum << endl;

            //int dp[n+1][1 + (totalsum/2)];
            //memset(dp, 0, sizeof(dp));
            loop(j, 0, 1 + totalsum/2) dp[0][j] = 0;

            loop(i, 1, n+1) {
                loop(j, 0, (totalsum/2) + 1 ) {
                    if (a[i-1] > j) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = max(dp[i-1][j-a[i-1]] + a[i-1], dp[i-1][j]);
                    }
                }
            }
            if (dp[n][totalsum/2] == totalsum/2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
	}
	return 0;
}
