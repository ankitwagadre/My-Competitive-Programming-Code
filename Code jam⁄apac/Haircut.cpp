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
#define MAXL                   1e18
#define MINL                   -1e18
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
ll mod(ll a, ll md = MOD) { ll r = a % md;  return r < 0 ? r + md : r; }
int stringtobits(string s) {    int n = 0;  loop(i, 0, s.size()) n = (n<<1) | (s[i] - '0');  return n; }

ll stringtoint(string s) {  ll j = 0, n = 0, sign = 1;
    if (s[0] == '-') { j++; sign = -1; }
    loop(i, j, s.size()) { n = n*10 + s[i] - '0'; }
    return n*sign;
}

int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

ll b, n;
ll m[1005];

ll cntTime(ll k) {
    ll l = 0;
    ll u = MAXL;
    ll cnt = 0;
    ll ans = 0;
    ll anscnt = 0;
    while(l < u) {
        cnt = 0;
        ll md = mid(l, u);
        loop(i, 0, b) {
            cnt += md/m[i] + 1;
        }

        if (cnt < k) {
            l = md+1;
        } else {
            ans = md;
            anscnt = cnt;
            u = md;
        }
    }

    //cout << anscnt << " " << k<<endl;
    ll rtval = 0;
    rloop(i, 0, b) {
        if (ans%m[i] == 0) {
           // cout << i + 1 << " ";
            if (anscnt == k)  {rtval = i+1; break;}
            anscnt--;
        }
    }

    return rtval;
}

int main() {
    //freopen("A-large-practice.in","rt",stdin);
    freopen("B-small-practice.in","rt",stdin);
	//freopen("B1_large.out","wt",stdout);

	int t;
	cin >> t;
	for(int f = 1; f <=t; f++)
    {

        cin >> b >> n;
        //if (f == 36) cout << b << " " << n << endl;
        loop(i, 0, b) {
            cin >> m[i];
          //  if (f == 36) cout << m[i] << " ";
        }

        int ans = 0;
        if (n <= b) {
            ans = n;
        } else {
            ans = cntTime(n);
        }

        cout << "Case #"<< f << ": ";
        cout << ans;
        cout << endl;
    }

	return 0;
}
