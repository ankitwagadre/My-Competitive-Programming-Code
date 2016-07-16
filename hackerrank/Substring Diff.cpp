
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
        int s;
        cin >> s >> a >> b;
        int n = a.size();

        int d[n+1][n+1];
        memset(d, 0, sizeof(d));

        for(int i = 0; i < n; i++) {
            int k = i;
            int j = 0;
            int cnt = 0;
            while(k<n) {
                if(a[k] != b[j]) cnt++;
                k++;
                j++;
            }
            d[i][0] = cnt;
        }

        for(int j = 0; j < n; j++) {
            int k = j;
            int i = 0;
            int cnt = 0;
            while(k<n) {
                if(a[i] != b[k]) cnt++;
                k++;
                i++;
            }
            d[0][j] = cnt;
        }

        int ans = 0;
        bool found = false;
        for(int l = n; l >= 1; l--) {
            for(int i = 0; i + l - 1 < n; i++) {
                for(int j = 0; j + l - 1 < n; j++) {
                    if (d[i][j] <= s) {
                        found = true;
                        ans = l;
                        break;
                    }
                    if (a[i]!= b[j]) {
                        d[i+1][j+1] =
                    }
                }
                if (found) break;
            }
        }

        cout << ans << endl;
    }

	return 0;
}
