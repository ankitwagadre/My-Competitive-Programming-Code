
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

int main() {
    freopen("C-large-practice.in","rt",stdin);
    //freopen("C-small-practice.in","rt",stdin);
	freopen("A_large.out","wt",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <=t; i++)
    {
        cout << "Case #"<< i << ": ";
        int n, k;
        cin >> n >> k;
        vector<int> c;
        loop(j, 0, n)
        {
            int a;
            cin >> a;
            c.pb(a);
        }
        int c_osz = 0;
        while (c_osz != c.size())
        {
            c_osz = c.size();
            for(int j = c.size() - 1; j < c.size(); j--)
                if (j-2 >= 0)
                {
                    if (c[j] - c[j-1] == k && c[j-1]-c[j-2] == k)
                    {
                        c.erase(c.begin() + j - 2);
                        c.erase(c.begin() + j - 2);
                        c.erase(c.begin() + j - 2);
                        break;
                    }
                }
        }

        cout << c.size();
        cout << endl;
    }
	return 0;
}
