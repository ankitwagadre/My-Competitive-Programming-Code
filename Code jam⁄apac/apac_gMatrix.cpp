/**************************
*   Ankit Wagadre
*   ankitwagadre@github.com
**************************/
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

ll mod(ll a, ll md = MOD) {
    ll r = a % md;
    return r < 0 ? r + md : r;
}

int a[3010];
int b[3010];
int m[3010][3010];
int n = 0, c = 0, k = 1, x = MOD;

int main() {
    /**** this method is slow ****/
    /*** faster way to do this is to use sets less number of comparison ***/
    //freopen("A-large-practice1.in","rt",stdin);
    freopen("D-large-practice.in","rt",stdin);
	//freopen("D_large.out","wt",stdout);
	int t;
	cin >> t;
	for(int f = 1; f <=t; f++)
    {
        cin >> n >> k >> c >> x;
        loop(i, 0, n) cin >> a[i];

        loop(i, 0, n) cin >> b[i];
        c = c%x;

        loopl(i, 0, n) {
            loopl(j, 0, n) {
                m[i][j] = ((a[i]*(i+1) + b[j]*(j+1))%x + c)%x;
            }
        }

        loop(j, 0, n) {
            loop(i, 0, n - k + 1) {
                loop(b, i, i+k) {
                    if(m[i][j] < m[b][j])
                        m[i][j] = m[b][j];
                }
            }
        }

        ll ans = 0;
        loop(i, 0, n - k + 1) {
            loop(j, 0, n - k + 1) {
                loop(b, j, j+k) {
                    if(m[i][j] < m[i][b]) m[i][j] = m[i][b];
                }
                ans = ans + (ll)m[i][j];
            }
        }

        cout << "Case #"<< f << ": ";
        cout << ans;
        cout << endl;
    }
	return 0;
}

