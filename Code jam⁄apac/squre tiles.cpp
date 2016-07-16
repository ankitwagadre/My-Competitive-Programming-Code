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
ll mod(ll a, ll md = MOD) { ll r = a % md;  return r < 0 ? r + md : r; }
int stringtobits(string s) {    int n = 0;  loop(i, 0, s.size()) n = (n<<1) | (s[i] - '0');  return n; }

ll stringtoint(string s) {  ll j = 0, n = 0, sign = 1;
    if (s[0] == '-') { j++; sign = -1; }
    loop(i, j, s.size()) { n = n*10 + s[i] - '0'; }
    return n*sign;
}

int main() {
    freopen("A-large-practice2.in","rt",stdin);
    //freopen("A-small-practice2.in","rt",stdin);
	freopen("A_large.out","wt",stdout);
	int t;
	cin >> t;
	for(int f = 1; f <=t; f++)
    {
        int r, c;
        cin >> r >> c;
        string s[r];
        loop(i, 0, r) {
            cin >> s[i];
        }

        bool possible = true;
        loop(i, 0, r) {
            loop(j, 0, c) {
                if (s[i][j] == '#')
                {
                    if (s[i+1][j+1] == '#' && s[i][j+1] == '#' && s[i+1][j] == '#')
                    {
                        s[i][j] = '/';
                        s[i+1][j+1] = '/';
                        s[i][j+1] = '\\';
                        s[i+1][j] = '\\';
                    } else {
                        //cout << i << j << endl;
                        possible = false;
                        break;
                    }
                }
            }
            if (!possible) break;
        }


        cout << "Case #"<< f << ":" << endl;
        if (possible) {
                loop(i, 0, r) cout << s[i] << endl;
        } else {
            cout << "Impossible" << endl;
        }
        //cout << endl;
    }

	return 0;
}
