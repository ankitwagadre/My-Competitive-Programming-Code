
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

bool key[10];
int ans[1000001];

int keypress(int a)
{
    if (a == 0)
        return 0;

    if (ans[a] != 0)
        return ans[a];
    int k = a;
    bool possible = true;
    int cnt = 1;
    while(k)
    {
        if (key[k%10])
        {
            k = k/10;
            cnt++;
        }
        else
        {
            possible = false;
            break;
        }
    }

    if (possible)
        return cnt;

    ans[a] = -1;
    for(int i = a/2; i > 0; i--)
    {
        if (a%i == 0 && keypress(a/i) != -1 && keypress(i) != -1)
        {
            if (ans[a] == -1) ans[a] = keypress(a/i) + keypress(i);
            else if ( ans[a] > keypress(a/i) + keypress(i)) ans[a] = keypress(a/i) + keypress(i);
        }
    }

    return ans[a];
}

int main() {
    freopen("C-large-practice.in","rt",stdin);
    //freopen("C-small-practice.in","rt",stdin);
	freopen("A_large.out","wt",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <=t; i++)
    {
        cout << "Case #"<< i << ": ";
        memset(key, false, sizeof(key));
        fill(ans, ans + 1000011, 0);

        loop(j, 0, 10)
        {
            int a;
            cin >> a;
            key[j] = a;
            //ky.pb(j);
        }

        int x;
        cin >> x;
        if (keypress(x) == -1)
            cout << "Impossible";
        else
            cout << keypress(x);

        cout << endl;
    }
	return 0;
}
